#
# Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
# All rights reserved.
# This component and the accompanying materials are made available
# under the terms of "Eclipse Public License v1.0"
# which accompanies this distribution, and is available
# at the URL "http://www.eclipse.org/legal/epl-v10.html".
#
# Initial Contributors:
# Nokia Corporation - initial contribution.
#
# Contributors:
#
# Description: 
#
#client for coverage testing

import getopt
import time,os,sys,re
from socket import *
from StringIO import *
host = "localhost"
port = 3555
build_command = "bldmake bldfiles & abld build winscw udeb"
unittest_build_command = "bldmake bldfiles & abld build winscw udeb & ..\\..\\Group\\bldmake bldfiles & ..\\..\\Group\\abld test build winscw udeb"
clean_command = "abld reallyclean"
copy_command = "copy Z:\\epoc32\\release\\winscw\\udeb\\UT_*.dll Z:\\epoc32\\release\\winscw\\udeb\\Z\\sys\\bin\\ & copy Z:\\epoc32\\release\\winscw\\udeb\\MT_*.dll Z:\\epoc32\\release\\winscw\\udeb\\Z\\sys\\bin\\"

def buildProfiledBinaries(aPath,aBuildCommand,aIdbName):
    os.chdir(aPath)
    os.putenv("CODETEST_LIB","NTmvc_TargetLibMD.lib ctsymbiannativemem.lib")
    os.putenv("CTDRIVER_ARGS","-CTsize_t=unsigned -CTtag-allocator -CTv -CTno-tag-includes -CTtag-level=SC -CTidb=" + aIdbName)
    os.system(clean_command)
    os.system(aBuildCommand)
    os.putenv("CODETEST_LIB","") # put env vars back
    os.putenv("CTDRIVER_ARGS","")

def buildModuleTests(aPath,aBuildCommand):
    os.chdir(aPath)
    os.system(aBuildCommand)
    os.system(copy_command)
    
def startProfiling(aFullIdbName, aExecutable):
    s = socket(AF_INET, SOCK_STREAM)
    s.connect((host,port))
    s.send(aFullIdbName + "," + aExecutable)
    data = s.recv(8192)
    s.close()
    return data

def parseAndWriteReport(aData, aReportLocation):
    filename = None
    date = None
    covered = None
    not_covered = None
    s = StringIO(aData)
    
    for line in s:
        idb_match = re.match(r"^\s+(?P<filename>.*\.idb$)", line)
        time_match = re.match(r"^\s+\w+-\w+\s+(?P<day_name>\w+)\s+(?P<month_name>\w+)\s+(?P<day_number>\d+)\s+(?P<time>\d+:\d+:\d+)\s+(?P<year>\d+$)", line)
        covered_match = re.match(r"^\s+\d+\s+(?P<coverage>\d+\.\d+)%\s+covered$", line)
        if idb_match is not None:
            filename = idb_match.group('filename')
        if time_match is not None:            
            date = time_match.group('day_number') + "-" + time_match.group('month_name') + "-" + time_match.group('year') + "-" + time_match.group('time').replace(":","")
        if covered_match is not None:
            covered = covered_match.group('coverage')
            not_covered = 100 - float(covered)
        if filename is not None and date is not None and covered is not None:
            break            
    s.close()    
    # write report to location
    print filename
    print date
    print covered
    
    
def cleanSystem(aComponentPath,aCleanCommand):
    os.chdir(aComponentPath)
    os.system(aCleanCommand)
    
def main():
    try:    
        opts, args = getopt.getopt(sys.argv[1:], 'b:i:e:u:r:', ['binary-buildpath=','idb-name=','executable=','unittest-buildpath=', 'report-location='])
        binary_buildpath = None
        idb_name = None
        executable = None
        unittest_buildpath = None
        report_location = None
        p = re.compile(r'/$')
        
        for o, a in opts:
            if o in ("-b", "--binary-buildpath"):
                binary_buildpath = a.replace("\\", "/")
                binary_buildpath = p.sub('', binary_buildpath)
            if o in ("-i", "--idb-name"):
                idb_name = a
            if o in ("-e", "--executable"):
                executable = a.replace("\\", "/")
            if o in ("-u", "--unittest-buildpath"):
                unittest_buildpath = a.replace("\\", "/")
                unittest_buildpath = p.sub('', unittest_buildpath)
            if o in ("-r", "--report-location"):
                report_location = a.replace("\\", "/")
                report_location = p.sub('', report_location)
                
        if (binary_buildpath is None) or (idb_name is None) or (executable is None) or (unittest_buildpath is None) or (report_location is None):
            usage()
            sys.exit(1)
        else:
            buildProfiledBinaries(binary_buildpath, build_command, idb_name)
            buildModuleTests(unittest_buildpath, unittest_build_command)
            report = startProfiling(binary_buildpath + "/" + idb_name, executable)
            parseAndWriteReport(report,report_location)
            cleanSystem(binary_buildpath, clean_command)
            cleanSystem(unittest_buildpath, clean_command)
            
    except getopt.GetoptError:
        usage()
        sys.exit(2)
      
def usage():
    print "Usage: <script> -b[--binary-buildpath=] binary build path, e.g. x:/s60/mw/project/group\n"
    print "                -i[--idb-name=] idb name for profiled source, e.g. project1.idb\n"
    print "                -e[--executable=] name of the executeable that should be run for profiled code, e.g. \"x:/epoc32/.../exerunner -arg1 -arg2\"\n"
    print "                -u[--unittest-buildpath=] path for unit tests to be build"
    print "                -r[--report-location=] report location, e.g. x:/s60/mw/somecomponent/reports"
    print " -b x:/.../group -i project.idb -e \"x:/..../exerunner.exe -arg1 -arg2\" -u x:/.../test/group -r x:/reports/component.txt"
    
main()
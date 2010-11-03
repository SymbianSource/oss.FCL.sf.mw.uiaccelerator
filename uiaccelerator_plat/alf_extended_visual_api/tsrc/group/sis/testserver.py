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
# server for coverage testing
#
# Usage:
# - start CodeTest Manager
# - start the command shell from CodeTest: File|CmdShell...
# - if this script file (testserver.py) is located for ex. in Z:\projects\uiaccelerator\uiaccelerator\uiacceltk\hitchcock\internal\tsrc\Test\Group
#   start the ctserver by giving a command in CodeTest command shell:
#   execfile('Z:/projects/uiaccelerator/uiaccelerator/uiacceltk/hitchcock/internal/tsrc/Test/Group/testserver.py')
# - the ctserver should now print:
#   Server Initialised...
#   Listening...
#   ctserver is communicating to the CodeTEST host on port 3020
#   ready.
#
# - open a windows command window in in Z:\projects\uiaccelerator\uiaccelerator\uiacceltk\hitchcock\internal\tsrc\Test\Group
# - start the client by running client.py in the windows command window
#
# Client usage:
#                <script> -b[--binary-buildpath=] binary build path, e.g. x:/s60/mw/project/group\n"
#                -i[--idb-name=] idb name for profiled source, e.g. project1.idb\n"
#                -e[--executable=] name of the executeable that should be run for profiled code, e.g. \"x:/epoc32/.../exerunner -arg1 -arg2\"\n"
#                -u[--unittest-buildpath=] path for unit tests to be build"
#                -r[--report-location=] report location, e.g. x:/s60/mw/somecomponent/reports"
#
# An example client command line:
#   client.py -b Z:\projects\uiaccelerator\uiaccelerator\group -i EunitTests.idb -e Z:\epoc32\release\winscw\udeb\EUnitExeRunner.exe -u Z:\projects\uiaccelerator\uiaccelerator\uiacceltk\hitchcock\internal\tsrc\Test\Group -r .
#

import time,os,sys,re
from ctest import CTCommonDef
from ctest.DataObjM import CovObjDef
from socket import *

ctServerPath = "C:\\APPS\\ct\\bin\\ctserver.exe"
host = ""
port = 3555

def initialise():
    os.spawnv(os.P_NOWAIT, ctServerPath, [''])
    print "Server Initialised..."

def processCommand(aSocket, aCommand):    
    if aCommand == "EXIT":
        sys.exit(0)
    else:
        commands = re.split(r',',aCommand)
        print "Retreived commands:",commands
        data = runCodeTest(commands[0], commands[1])
        aSocket.send(data)
                
def runCodeTest(aIdb, aExecutable):
    ctob.closeWorkspace()
    ds = ctob.createCtSWIC('localhost', 3020, 30)
    print ds.getName(), 'Data source created...'
    ds.setIDB(aIdb)
    ds.connect()
    ds.setContinuousMode()
    ds.start()
    print 'Starting profiled application...'
    os.spawnv(os.P_WAIT, aExecutable, [' /e S60AppEnv /r Warning /w 1'])
    print 'Application exited...'
    time.sleep(10)
    print 'Collecting data...'
    ds.collectData()    
    ds.stop()
    covObject0 = ds.getCoverageObjs()[0]
    covObject0.sortData('coverage',1)
    # html report / per method
    #covObject0.exportView('c:/cov_data_one.htm', CTCommonDef.HTML_FORMAT,' ',' ' )
    covObject0.writeCoverageReport('/cov_report.txt', CovObjDef.OVERALL_SUMMARY)
    f = open("/cov_report.txt")
    data = f.read()
    f.close()
    ds.disConnect()
    print 'Report sent to the client...'
    return data
        
def startServer():
    s = socket(AF_INET, SOCK_STREAM)
    s.bind((host,port))
    s.listen(1)
    print "Listening..."
    while 1:
        (clientsocket, address) = s.accept()
        print "Client connected..."
        while 1:
            buff = clientsocket.recv(4096)
            print "Data received..."
            if buff:
                processCommand(clientsocket, buff)
            else: 
                break
        clientsocket.close()
    
initialise()
startServer()
import os
import sys

import buildinfra.compile as bic
import buildinfra.subprocessmanagement.manager as spm

class Tester:
    class Test:
        def __init__(self, exe, command_lines):
            self.exe = exe
            self.command_lines = command_lines

        def AllCommands(self, exe_output):
            return [os.path.join(exe_output, self.exe) + ' ' + cl for cl in self.command_lines]

    def __init__(self):
        self.compiler = bic.Compile()
        self.compiler.RegisterMacro("DEBUG")
        self.tests = dict()

    def RegisterTest(self, test, dependencies, command_lines):
        self.compiler.RegisterTarget( test, dependencies )
        self.tests[test] = self.Test(test, command_lines)
    
    def Run(self):
        successful_builds = self.compiler.Run()
        
        runs = []
        for build in successful_builds:
            for r in self.tests[build].AllCommands(self.compiler.output_dir):
                runs.append( r )

        for idx, run in enumerate(runs):
            self.__print_run(idx, run)
            manager = spm.Manager(run, [sys.stdout], dict())
            if manager.Run() != 0:
                print("@@@ RUN " + str(idx) + " FAILED")

    def __print_run(self, idx, run):
        print("============================================================")
        print("============================================================")
        print("Run [" + str(idx) + "]: " + run)

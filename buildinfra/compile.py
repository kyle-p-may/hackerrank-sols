import os
import sys

import buildinfra.subprocessmanagement.manager as spm

class Compile:

    def __init__(self, output_dir = "build"):
        self.cxx = "g++"
        self.output_dir = output_dir
        self.targets = dict()
        self.flags = ["-std=c++17", "-Wall", "-Werror"]
        self.include_dirs = []
        self.macros = []

    def RegisterTarget(self, target, dependencies):
        self.targets[target] = dependencies

    def RegisterCompilerFlag(self, flag):
        self.flags.append( flag )

    def RegisterMacro(self, macro):
        self.macros.append( macro )

    def Run(self):
        successful_builds = []
        for target in self.targets.keys():
            cmd = self.__build_compiler_command(target)
            print(cmd)
            manager = spm.Manager(cmd, [sys.stdout], dict())
            if manager.Run() == 0:
                successful_builds.append( target )

        return successful_builds

    def __build_output_name(self, target_name):
        return os.path.join(self.output_dir, target_name)

    def __build_compiler_command(self, target):
        cmd_components = [self.cxx]
        for f in self.flags:
            cmd_components.append(f)

        for d in self.include_dirs:
            cmd_components.append( "-L" + d )

        for m in self.macros:
            cmd_components.append( "-D" + m )

        cmd_components.append( "-o" )
        cmd_components.append( self.__build_output_name(target) )

        for dep in self.targets[target]:
            cmd_components.append( dep )

        return " ".join(cmd_components)

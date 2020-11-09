import os
import buildinfra.tester as bit

main_dir = "coinchangeproblem"
input_dir = os.path.join(main_dir, "input")
input_files = [ "test0.in", "test1.in" ]
cla = [ "< " + os.path.join(input_dir, x) for x in input_files ]

tester = bit.Tester()
tester.RegisterTest("main.exe", [os.path.join(main_dir, "main.cpp")], cla)

tester.Run()

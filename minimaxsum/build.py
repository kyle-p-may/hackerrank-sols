import buildinfra.tester as bit

tester = bit.Tester()
tester.RegisterTest("main.exe", ["minimaxsum/minimaxsum_main.cpp"], ["< minimaxsum/input/test1.in"])

tester.Run()

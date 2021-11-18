./check : 从data中创造数据，并分别在std和test中运行(获得运行时间)比较，直至答案不同
./cmp : 比较test.out和test.ans
./complie sth : c++14编译
./data : 创造数据
./run sth: 从test.in中读取数据运行（获得运行时间），输出到test.out，如果省略参数，视为test
./std : 运行std
./test : 运行test

使用方法：在vscode中打开work目录，在终端中使用即可。
可能出现的问题：
1.没有找到g++
	linux下安装build-essential
	windows下将MinGW\bin加入到环境变量path
2.linux下没有找到/usr/bin/time
	安装time
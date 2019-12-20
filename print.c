extern area;
void welcome(){
	print("---------------------"); 
	print("学生成绩管理系统");
	print("梁笑尘 黄华映 马汶研 林萱仪 制作");
}

void printMenu(){
	print("---------------------"); 
	print("主界面");
	print(getArea());
	print("1 更换范围");
	print("2 排序并输出");
	print("3 查找、修改");
	print("4 密码修改");
	print("0 退出");
}


本程序由Qt 创建，基本功能是将输入的自然数进行十进制、二进制、十六进制、八进制之间的转换；

1. 关键在于应用了QtString类的.setNum成员，来完成进制的转换
2. result_temp 成员保存当前的result值来防止result一直增加


EXC_BASE:
	mfc0    $k0, $cause         #读CP0 cause寄存器
	andi    $k1, $k0, 0xC000    #读取ExcCode
	srl     $k1, $k1, 14        #将ExcCode移到$k1最后两位
	andi    $k0, $k0, 0x00FF    #将vector存到$k0后八位
	add     $t0, $zero, $zero   #index变量
LOOP:
# t1 = { ExcCode1, ExcCode0,6'h0 ,vector(8'b),funciton_location(16'b)};
	lw      $t1, 0($t0)         #从存储器中取值
	beq     $t1, $t0, ERET      #如果全0,说明没找到，跳到返回
	srl     $t2, $t1, 16        #将$t1逻辑右移16位
	srl     $t3, $t2, 14        #将$t2逻辑右移14位，将ExcCode放置在$t3的最低两位
	andi    $t2, $t2, 0x00FF    #取$t2后八位vector

	bne     $k1, $t3, LOOP      #判断ExcCode是否相等，不相等则返回继续查找
	bne     $k1, $zero,  JUMP      #判断ExcCode是否为00，不相等则跳转到函数出口
	bne     $k0, $t2, LOOP      #判断vector是否相等，不相等则返回继续查找

JUMP:
	andi    $t4, $t1, 0x00FF    #获取中断向量
	jr      $t4
ERET:
eret


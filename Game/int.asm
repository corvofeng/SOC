#  2017-9-23
#
# 中断处理程序
#    中断处理程序属于BIOS的一部分, 我打算使用汇编语言进行编写
#
# 中断或是异常来临时, cp0寄存器组保存中断信息, 同时, pc指向中断处理程序的入口地址
#   中断程序中会进行如下动作
#       1. 关闭中断
#       2. 保存现场,(32个通用寄存器, 以及CP0相关寄存器)
#       3. 查看中断向量号, 以确认中断源
#       4. 调用该中断号对应的中断处理程序
#       5. 恢复上下文
#       6. 开启中断
#       6  中断返回
# Attention:
#    本次的SOC设计中, 只有4x4键盘为输入型中断, 并且, 有特别的位置当做键盘输入的缓冲区, 
#  所以, 上下文信息中, 不需要保存全部的32个寄存器
#

int_pro:        # 中断处理程序, 为固定位置
    # 关中断




    # 开中断


    # 中断返回
    eret
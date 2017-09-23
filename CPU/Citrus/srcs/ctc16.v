`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 2016/12/01 15:05:19
// Design Name:
// Module Name: ctc16
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////




module ctc16(
           rdata,wdata,CS,CLK,Reset,pulse0,pulse1,address,IOW,IOR,COUT0,COUT1
       );
input[15:0] wdata;//cpu写数据
input[15:0] address;//端口地址
input CS,CLK,Reset,pulse0,pulse1,IOW,IOR;//片选端，时钟端，复位信号，外部脉冲信号，写信号，读信号
output [15:0] rdata;//cpu读数据
output COUT0;//定时/计数器输出
output COUT1;//定时/计数器1输出


reg[15:0] state,state1;/*方式/状态寄存器
15:定时/计数有效位
3：计数到（状态）
2：定时到（状态）
1：重复方式
0：工作方式：定时/计数
*/
reg[15:0] init,init1;//初值寄存器
reg[15:0] rda;//rdata的驱动寄存器
reg COU,COU1;//COUT0的驱动寄存器
integer count0,count1;//计数值
integer init_tmp,init1_tmp;//用来暂存定时器初值
assign rdata=rda;//驱动
assign COUT0=COU;
assign COUT1=COU1;


initial
begin
    count0=0;//用于计数
    count1=0;
end


always @(posedge CLK)
begin
    if(CS)
    begin
        if(Reset)
        begin
            state[15:0]=16'h0000;
            state1[15:0]=16'h0000;
            init[15:0]=16'h0000;
            init1[15:0]=16'h0000;
            count0=0;
            count1=0;
            init_tmp=0;
            init1_tmp=0;
        end
        if(IOW)//CPU写数据
        begin
            /*if(address[7:0]==8'h20) state=wdata;//CPU写方式寄存器
                else if(address[7:0]==8'h24) 
                begin
                 init=wdata;//CPU写初值寄存器
                init_tmp=init;//init_tmp用来备份初值寄存器的值
                end*/
            case(address[3:0])
                4'h0:state=wdata;
                4'h4:begin
                    init=wdata;//CPU写初值寄存器
                    init_tmp=init;//init_tmp用来备份初值寄存器的值
                end
                4'h2:state1=wdata;
                4'h6:begin
                    init1=wdata;//CPU写初值寄存器
                    init1_tmp=init1;//init1_tmp用来备份初值寄存器的值
                end
            endcase
        end


        if(IOR)//CPU读数据
        begin
            //     if(address[7:0]==8'h20)
            //         begin
            //         rda=state;//CPU读状态寄存器
            //         state[3:2]=2'b00;//状态寄存器读取后清零
            //         state[15]=0;
            // //         COU2=count2;
            //         end
            //     else if(address[7:0]==8'h24) rda=init;//CPU读初值寄存器
            case(address[3:0])
                4'h0:begin
                    rda=state;//CPU读状态寄存器
                    state[3:2]=2'b00;//状态寄存器读取后清零
                    state[15]=0;
                end
                4'h4:rda=init;//CPU读初值寄存器

                4'h2:begin
                    rda=state1;//CPU读状态寄存器
                    state1[3:2]=2'b00;//状态寄存器读取后清零
                    state1[15]=0;
                end
                4'h6:rda=init1;//CPU读初值寄存器

            endcase
        end

        if(!state[0])//定时
        begin
            if({state[1],state[0]}==2'b00)//读方式寄存器，非循环定时
            begin
                state[15]=1;//写状态寄存器，定时开始
                if(init==1)//初值寄存器减到1，定时结束
                begin
                    state[15]=0;//定时结束
                    state[3:2]=2'b01;//定时到
                    COU=0;//定时到输出一个低电平
                end
                else if(init>1)//尚未定时到
                begin
                    init=init-1;//初值减1
                    COU=1;//平时输出高电平
                end
                else COU=1;
            end
            else if({state[1],state[0]}==2'b10)//循环定时
            begin
                state[15]=1;//写状态寄存器，定时开始
                if(init==1)//初值寄存器减到1，定时到
                begin
                    state[3:2]=2'b01;
                    init=init_tmp;//init_tmp保存的初值再赋值给init寄存器
                    COU=0;//定时到输出一个低电平
                end
                else if(init==init_tmp)
                begin
                    state[3:2]=2'b00;//清除定时到
                    init=init-1;
                    COU=1;
                end
                else
                begin
                    init=init-1;
                    COU=1;//平时输出高电平
                end
            end
        end
        else begin
            COU=1;
            // state[15]=0;//没有处在定时的状态
        end


        if(!state1[0])//cnt1定时
        begin
            if({state1[1],state1[0]}==2'b00)//读方式寄存器，非循环定时
            begin
                state1[15]=1;//写状态寄存器，定时开始
                if(init1==1)//初值寄存器减到1，定时结束
                begin
                    state1[15]=0;//定时结束
                    state1[3:2]=2'b01;//定时到
                    COU1=0;//定时到输出一个低电平
                end
                else if(init1>1)//尚未定时到
                begin
                    init1=init1-1;//初值减1
                    COU1=1;//平时输出高电平
                end
                else COU1=1;
            end
            else if({state1[1],state1[0]}==2'b10)//循环定时
            begin
                state1[15]=1;//写状态寄存器，定时开始
                if(init1==1)//初值寄存器减到1，定时到
                begin
                    state1[3:2]=2'b01;
                    init1=init1_tmp;//init_tmp保存的初值再赋值给init寄存器
                    COU1=0;//定时到输出一个低电平
                end
                else if(init1==init1_tmp)
                begin
                    state1[3:2]=2'b00;//清除定时到
                    init1=init1-1;
                    COU1=1;
                end
                else
                begin
                    init1=init1-1;
                    COU1=1;//平时输出高电平
                end
            end
        end
        else begin
            COU1=1;
            // state1[15]=0;//没有处在定时的状态
        end


        if(state[0])//cnt0计数，从0开始计数
        begin
        if(pulse0)begin
            if({state[1],state[0]}==2'b01)
            begin
                state[15]=1;//计数开始
                begin
                    if(count0==init)//计数值等于初值
                    begin
                        state[15]=0;//计数结束
                        state[3:2]=2'b10;//设置状态寄存器，计数到
                    end
                    else begin
                        count0=count0+1;//计数
                        //                  count2=count2+1;//测试
                    end
                end
            end
            else if({state[1],state[0]}==2'b11)//循环计数
            begin
                state[15]=1;//计数开始
                if(count0==init)//计数值等于初值
                begin
                    state[3:2]=2'b10;//设置状态寄存器，计数到
                    count0=1;//循环，重置计数值寄存器
                    //             count2=count2+1;//测试
                end
                else if(count0==1)
                begin
                    state[3:2]=2'b00;//清除状态寄存器
                    count0=count0+1;
                    //             count2=count2+1;//测试
                end
                else begin
                    count0=count0+1;//计数
                    //              count2=count2+1;//测试
                end
            end
        end
        end else state[15]=0;//没有处在计数的状态state[15]为0


        if(state1[0])//cnt1计数，从0开始计数
        begin
            if(pulse1)begin
                if({state1[1],state1[0]}==2'b01)
                begin
                    state1[15]=1;//计数开始
                    begin
                        if(count1==init1)//计数值等于初值
                        begin
                            state1[15]=0;//计数结束
                            state1[3:2]=2'b10;//设置状态寄存器，计数到
                        end
                        else begin
                            count1=count1+1;//计数
                            //                  count2=count2+1;//测试
                        end
                    end
                end
                else if({state1[1],state1[0]}==2'b11)//循环计数
                begin
                    state1[15]=1;//计数开始
                    if(count1==init1)//计数值等于初值
                    begin
                        state1[3:2]=2'b10;//设置状态寄存器，计数到
                        count1=1;//循环，重置计数值寄存器
                        //             count2=count2+1;//测试
                    end
                    else if(count1==1)
                    begin
                        state1[3:2]=2'b00;//清除状态寄存器
                        count1=count1+1;
                        //             count2=count2+1;//测试
                    end
                    else begin
                        count1=count1+1;//计数
                        //              count2=count2+1;//测试
                    end
                end
            end
        end else state1[15]=0;//没有处在计数的状态state[15]为0

    end//CS
end//always


endmodule

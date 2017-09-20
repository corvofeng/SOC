/*
 *=============================================================================
 *    Filename: rom64k.v
 *
 *     Version: 1.0
 *  Created on: September 19, 2017
 *
 *      Author: corvo
 *=============================================================================
 */
`timescale 1ns / 1ps


/**
 * 此接口为封装好的rom, 
 * 数据初始化: 
 * 双击genRom, 选择RST&initialization页面, 添加coe文件, 注意路径中不要带中文
 */
module rom64k(addr, data);
    input [15:0] addr;
    output [31:0] data;

    dist_mem_gen_rom gemRom(
        .a(addr),
        .spo(data)
    );
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 06/29/2020 09:01:39 AM
// Design Name: 
// Module Name: Frame_flag
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


module Frame_flag(
    input dclk_in,
    input [31:0] data_in,
    input Vsync_in,
    input Hsync_in,
    input [16:0] Pixel_cnt,
    input [16:0] Max_pixel_cnt,
    output reg [31:0] data_out
    );
    reg counter = 0;
    reg signal_d;
    reg signal_Vsync;
    reg signal_Vsync_old;
    reg negedge_Vsync;
    always @(dclk_in)
    begin

    //Vsync negedge detector
    signal_d            <= Vsync_in;
    signal_Vsync        <= signal_d;
    signal_Vsync_old    <= signal_Vsync;
    negedge_Vsync = signal_Vsync_old & (!signal_Vsync);

    //condition to flip the flag bit
    if((Pixel_cnt == Max_pixel_cnt) && (Vsync_in == 1) && (Hsync_in == 1))
    counter = counter+1;
    else 
    counter= counter;
    
    //assign data out
    data_out = {data_in[31:15], counter, data_in[13:0]};
    
    end
    
    
endmodule

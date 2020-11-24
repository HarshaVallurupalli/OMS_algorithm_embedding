`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/28/2020 02:52:38 PM
// Design Name: 
// Module Name: op_demux
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


module op_demux(
    input [3:0] gpio_io,
    output reg [3:0] gpio_io_o_0,
    output reg [3:0] gpio_io_o_1,
    output reg [3:0] gpio_io_o_2,
    output reg [3:0] gpio_io_o_3,
    input sel1,
    input sel2
    );
    
//gpio_io_o_0 <= gpio_io & sel;1111&0001-0001
reg sel;
    always @(sel1,sel2)
        begin
        
/*       sel ={sel2,sel1};
          case (sel)
          
           2'b00 :
               begin
                    gpio_io_o_0 <= gpio_io;
                    gpio_io_o_1 <= 0;
                    gpio_io_o_2 <= 0;
                    gpio_io_o_3 <= 0;    
               end
           2'b01 :
               begin
                    gpio_io_o_0 <= 0;
                    gpio_io_o_1 <= gpio_io;
                    gpio_io_o_2 <= 0;
                    gpio_io_o_3 <= 0; 
               end
           2'b10 :
               begin
                   gpio_io_o_0 <= 0;
                   gpio_io_o_1 <= 0;
                   gpio_io_o_2 <= gpio_io;
                   gpio_io_o_3 <= 0; 
               end
           2'b11 :
               begin
                   gpio_io_o_0 <= 0;
                   gpio_io_o_1 <= 0;
                   gpio_io_o_2 <= 0;
                   gpio_io_o_3 <= gpio_io; 
               end
           default:
               begin
                   gpio_io_o_0 <= gpio_io;
                   gpio_io_o_1 <= 0;
                   gpio_io_o_2 <= 0;
                   gpio_io_o_3 <= 0; 
               end
           endcase */  
        if (sel2==0 && sel1==0) 
        begin
            gpio_io_o_0 <= gpio_io;
            gpio_io_o_1 <= 0;
            gpio_io_o_2 <= 0;
            gpio_io_o_3 <= 0;  
        end
        else if (sel2==0 && sel1==1) 
        begin
            gpio_io_o_0 <= 0;
            gpio_io_o_1 <= gpio_io;
            gpio_io_o_2 <= 0;
            gpio_io_o_3 <= 0;        
        end
        else if (sel2==1 && sel1==0) 
        begin
            gpio_io_o_0 <= 0;
            gpio_io_o_1 <= 0;
            gpio_io_o_2 <= gpio_io;
            gpio_io_o_3 <= 0; 
        end
        else if (sel2==1 && sel1==1)
        begin
            gpio_io_o_0 <= 0;
            gpio_io_o_1 <= 0;
            gpio_io_o_2 <= 0;
            gpio_io_o_3 <= gpio_io; 
        end
        else
        begin
            gpio_io_o_0 <= gpio_io;
            gpio_io_o_1 <= 0;
            gpio_io_o_2 <= 0;
            gpio_io_o_3 <= 0;  
        end        
        end
endmodule

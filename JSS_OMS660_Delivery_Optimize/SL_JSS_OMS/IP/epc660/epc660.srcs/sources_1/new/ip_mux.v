`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/28/2020 02:13:56 PM
// Design Name: 
// Module Name: ip_mux
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


module ip_mux(
    input [11:0] data_in,
    input hsync_in,
    input vsync_in,
    input xsync_sat_in,
    input [11:0] data_in1,
    input hsync_in1,
    input vsync_in1,
    input xsync_sat_in1,
    input [11:0] data_in2,
    input hsync_in2,
    input vsync_in2,
    input xsync_sat_in2,
    input [11:0] data_in3,
    input hsync_in3,
    input vsync_in3,
    input xsync_sat_in3,
    output reg [11:0] data_out,
    output reg hsync_out,
    output reg vsync_out,
    output reg xsync_sat_out,
    input sel1,
    input sel2
    );
    reg [1:0]sel;

    
    always @(sel1,sel2)
    begin
      sel={sel2,sel1};
      case (sel)
      
       2'b00 :
       begin
       data_out        <=        data_in;
       hsync_out       <=        hsync_in;
       vsync_out       <=        vsync_in;
       xsync_sat_out   <=        xsync_sat_in;
       end
       
       2'b01 :
       begin 
       data_out        <=        data_in1;
       hsync_out       <=        hsync_in1;
       vsync_out       <=        vsync_in1;
       xsync_sat_out   <=        xsync_sat_in1;
       end
       
       2'b10 :
       begin 
       data_out        <=        data_in2;
       hsync_out       <=        hsync_in2;
       vsync_out       <=        vsync_in2;
       xsync_sat_out   <=        xsync_sat_in2;
       end
       
       2'b11 :
       begin 
       data_out        <=        data_in3;
       hsync_out       <=        hsync_in3;
       vsync_out       <=        vsync_in3;
       xsync_sat_out   <=        xsync_sat_in3;
       end
       default:
       begin
       data_out        <=        data_in;
       hsync_out       <=        hsync_in;
       vsync_out       <=        vsync_in;
       xsync_sat_out   <=        xsync_sat_in;
       end
       
       endcase    
    end
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 05/05/2020 03:53:00 PM
// Design Name: 
// Module Name: clockMux
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


module clockMux2(
    input dclk_in2,
    input dclk_in3,
    input sel1,
    output dclk_out2
    );
    

   BUFGMUX #(
   )  U0(
      .O(dclk_out2),   // 1-bit output: Clock output
      .I0(dclk_in2), // 1-bit input: Clock input (S=0)
      .I1(dclk_in3), // 1-bit input: Clock input (S=1)
      .S(sel1)    // 1-bit input: Clock select
   );


   // End of BUFGMUX_CTRL_inst instantiation
					
					
endmodule

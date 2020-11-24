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


module clockMux3(
    input dclk_in1,
    input dclk_in2,
    input sel2,
    output dclk_out
    );
    

   BUFGMUX #(
   )  U0(
      .O(dclk_out),   // 1-bit output: Clock output
      .I0(dclk_in1), // 1-bit input: Clock input (S=0)
      .I1(dclk_in2), // 1-bit input: Clock input (S=1)
      .S(sel2)    // 1-bit input: Clock select
   );


   // End of BUFGMUX_CTRL_inst instantiation
					
					
endmodule

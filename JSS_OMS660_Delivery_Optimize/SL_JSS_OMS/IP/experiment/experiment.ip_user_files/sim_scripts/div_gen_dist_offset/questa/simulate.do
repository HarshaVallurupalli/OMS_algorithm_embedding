onbreak {quit -f}
onerror {quit -f}

vsim -t 1ps -lib xil_defaultlib div_gen_dist_offset_opt

do {wave.do}

view wave
view structure
view signals

do {div_gen_dist_offset.udo}

run -all

quit -force

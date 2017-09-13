#!/bin/bash -f
xv_path="/run/media/corvo/Work/Vivado/Vivado/2016.2"
ExecStep()
{
"$@"
RETVAL=$?
if [ $RETVAL -ne 0 ]
then
exit $RETVAL
fi
}
ExecStep $xv_path/bin/xelab -wto b564e5385ea5425997b6464c781686d9 -m64 --debug typical --relax --mt 8 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot test_sim_behav xil_defaultlib.test_sim xil_defaultlib.glbl -log elaborate.log

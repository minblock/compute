#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.computecore/computed.pid file instead
compute_pid=$(<~/.computecore/testnet3/computed.pid)
sudo gdb -batch -ex "source debug.gdb" computed ${compute_pid}

#!/bin/bash

set -e

date
ps axjf

#################################################################
# Update Ubuntu and install prerequisites for running OVOCoin   #
#################################################################
sudo apt-get update
#################################################################
# Build OVOCoin from source                                     #
#################################################################
NPROC=$(nproc)
echo "nproc: $NPROC"
#################################################################
# Install all necessary packages for building OVOCoin           #
#################################################################
sudo apt-get install -y qt4-qmake libqt4-dev libminiupnpc-dev libdb++-dev libdb-dev libcrypto++-dev libqrencode-dev libboost-all-dev build-essential libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libssl-dev ufw git
sudo add-apt-repository -y ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install -y libdb4.8-dev libdb4.8++-dev

cd /usr/local
file=/usr/local/ovocoinQT
if [ ! -e "$file" ]
then
        sudo git clone https://github.com/minblock/OVOCoinQt.git
fi

cd /usr/local/OVOCoinQt/src
file=/usr/local/OVOCoinQt/src/ovocoind
if [ ! -e "$file" ]
then
        sudo make -j$NPROC -f makefile.unix
fi

sudo cp /usr/local/OVOCoinQt/src/ovocoind /usr/bin/ovocoind

################################################################
# Configure to auto start at boot                                      #
################################################################
file=$HOME/.ovocoin
if [ ! -e "$file" ]
then
        sudo mkdir $HOME/.ovocoin
fi
printf '%s\n%s\n%s\n%s\n' 'daemon=1' 'server=1' 'rpcuser=u' 'rpcpassword=p' | sudo tee $HOME/.ovocoin/ovocoin.conf
file=/etc/init.d/ovocoin
if [ ! -e "$file" ]
then
        printf '%s\n%s\n' '#!/bin/sh' 'sudo ovocoind' | sudo tee /etc/init.d/ovocoin
        sudo chmod +x /etc/init.d/ovocoin
        sudo update-rc.d ovocoin defaults
fi

/usr/bin/ovocoind
echo "OVOCoin has been setup successfully and is running..."
exit 0


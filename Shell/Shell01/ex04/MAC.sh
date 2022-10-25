ifconfig -a | grep "ether " | tr -d " " | sed "s/ether//" | tr -d "\t"

echo Installing the following programs:
cat apt-install-list.txt | tr '\n' ' '

cat apt-install-list.txt | tr '\n' ' ' | sudo apt install -y

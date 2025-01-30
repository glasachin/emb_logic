# NMCLI

`sudo apt install network-manager -y`

`sudo systemctl enable NetworkManager`

`sudo systemctl start NetworkManager`

`sudo systemctl restart NetworkManager`

**List available wifi**

`nmcli device wifi list`

**Connecting to WiFi**

`nmcli device wifi connect "Your_SSID" password "Your_WiFi_Password"`

**Verify Connection**

`nmcli connection show --active`

`nmcli device status`

**auto connect on boot**

`nmcli connection modify "Your_SSID" connection.autoconnect yes`



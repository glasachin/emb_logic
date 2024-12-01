# Random Information


## Running Scripts on Reboot
one way is cronjob, but on some embedded devices `crontab` may not be available. In that case we can add the script to services and start the script on reboot.

```
cp <script_name> /etc/init.d/  # copy script at this location
update-rc.d <script_name> defaults  # update the script name in defaults
#reboot the system
```

`We need to make sure that the script has all necessary permissions`

If we stop the script to run on reboot then remove the script from that location.

## Disabling kernel msg on console

**Change Kernel Log Level Temporarily**

`sudo dmesg -n 1`

Log levels:
0: Emergency
1: Alert
2: Critical
3: Error
4: Warning
5: Notice
6: Informational
7: Debug (default)

**Use /proc/sys/kernel/printk**

View current setting: `cat /proc/sys/kernel/printk`

change the console log level: `sudo echo "1" > /proc/sys/kernel/printk`

**Make the Change Persistent**

To prevent messages from appearing on the console after a reboot, add the configuration to `sysctl`:

1. Edit the `sysctl.conf` file: `sudo nano /etc/sysctl.conf`
2. Add the following line: `kernel.printk = 1 4 1 7`
3. Apply the changes: `sudo sysctl -p`

**Redirect Kernel Messages to Another Console (Optional)**

`sudo echo "ttyS0" > /proc/sys/kernel/printk_dev`

**Stop Kernel Logs Entirely (Advanced)**

Remove the `console=` parameter from the kernel boot arguments in your bootloader
1.  edit `GRUB` config: `sudo nano /etc/default/grub`
2. remove or adjust `console=` line
3. Updatee `GRUB`: `sudo update-grub`






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
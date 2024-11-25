# Services During boot

This help to understand the services and how to run a file during boot.

1. we can create simple `.sh` file and put it into `init.d` file
    1. cp start_DCU_app.sh /etc/init.d/
    2. update-rc.d start_DCU_app.sh defaults
    3. reboot

2. Create a service


## init.d
init.d is a directory in Linux systems that contains scripts used to manage system services during the boot, shutdown, or runtime. These scripts follow the System V (SysV) init system, which was a traditional way of handling service initialization before being replaced by modern init systems like systemd in most Linux distributions.

### Purpose of init.d
The scripts in /etc/init.d/ are used to:

1. Start services (e.g., web servers, databases, daemons) during system boot.
2. Stop services during system shutdown.
3. Restart or reload services while the system is running.
Each script is typically associated with a specific service or daemon.

### Directory Location
The init.d directory is usually located at:

* /etc/init.d/

Some systems also use:

* /etc/rc.d/init.d/

### How init.d Works
**Runlevels:**

The SysV init system organizes the boot process into runlevels (0 to 6). Each runlevel defines a specific state of the system (e.g., multi-user mode, single-user mode, reboot, etc.).
The scripts in /etc/init.d/ are symlinked to corresponding runlevel directories (/etc/rc[0-6].d/) to control when they are executed.

**Script Naming:**

Scripts in /etc/rc[0-6].d/ are named with a prefix S (for "start") or K (for "kill") followed by a number indicating the order of execution. For example:
Copy code
S01apache2
K01apache2
Script Operations: Each script in /etc/init.d/ typically supports these operations:

start: Starts the service.
stop: Stops the service.
restart: Stops and starts the service.
reload: Reloads the service configuration without stopping it.
status: Checks the current status of the service.
Example of an init.d Script
Below is an example script for a service called myservice:

bash
Copy code
#!/bin/bash
### BEGIN INIT INFO
# Provides:          myservice
# Required-Start:    $network
# Required-Stop:     $network
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: My custom service
### END INIT INFO

case "$1" in
    start)
        echo "Starting myservice"
        # Command to start the service
        ;;
    stop)
        echo "Stopping myservice"
        # Command to stop the service
        ;;
    restart)
        echo "Restarting myservice"
        # Command to restart the service
        ;;
    status)
        echo "Checking status of myservice"
        # Command to check the service status
        ;;
    *)
        echo "Usage: /etc/init.d/myservice {start|stop|restart|status}"
        exit 1
        ;;
esac

exit 0
Common Commands
To manage services using init.d, you can run the following commands:

bash
Copy code
sudo /etc/init.d/<service_name> start    # Start a service
sudo /etc/init.d/<service_name> stop     # Stop a service
sudo /etc/init.d/<service_name> restart  # Restart a service
sudo /etc/init.d/<service_name> status   # Check service status

### Limitations of init.d
1. `Sequential Execution:` Scripts are executed one by one in sequence, which can slow down the boot process.
2. `No Dependency Management:` SysV init lacks robust dependency handling compared to modern systems like systemd.

### Modern Alternatives
Most modern Linux distributions have transitioned to `systemd` (e.g., Ubuntu, Fedora) or Upstart (older Ubuntu versions). These systems provide faster boot times and better dependency management.
To manage services in a systemd system, use:

```
sudo systemctl start <service_name>
sudo systemctl stop <service_name>
sudo systemctl restart <service_name>
sudo systemctl status <service_name>
```
Conclusion
init.d is an older but still relevant system for service management in Linux, especially on systems that use the SysV init framework. While most modern distributions have moved to systemd, understanding init.d is essential for working with legacy systems or custom embedded Linux environments.



## Through Systemd Service
we can create a `systemd service` file. There is a specific format for creating this file. 

**e.g. to run a script after login process is done** it is done to make user `USER` variable is there.

1. Create a service file: `sudo nano /etc/systemd/system/my-script.service`
2. content
```
[Unit]
Description=Run script after boot
After=multi-user.target

[Service]
Type=simple
ExecStart=/path/to/your/script.sh
Environment="USER=%I"

[Install]
WantedBy=multi-user.target
```
3. Enable and start the service
```
sudo systemctl enable my-script.service
sudo systemctl start my-script.service
```

### Creation of '.service' file
The systemd service file has three important and necessary sections. They are `[Unit]`, `[Service]` and `[Install]` sections. The systemd service file's extension is `.service` and we use the pound/hash symbol (#) for single line comments.

**The [Unit] section**

it contains details about the service. Details like 'what is its description', 'what are its dependencies' and more.

Below are the fields the Unit section has:

1. `Description`:- Human-readable title of the systemd service.
2. `After`:- Set dependency on a service. For example, if you are configuring Apache web server, you want the server to start after the network is online. This typically includes targets or other services.
3. `Before`:- Start current service before specified service. 

**The [Service] section**

The Service section contains details about the execution and termination of service.

Below are the fields the Service section has:

* `ExecStart`:- The command that needs to be executed when the service starts. In our case, we want the Apache server to start.
* `ExecReload`:- This is an optional field. It specifies how a service is restarted. For services that perform disk I/O (especially writing to disk, like a database), it is best to gracefully kill them and start again. Use this field in case you wish to have a specific restart mechanism.
* `Type`:- This indicates the start-up type of a process for a given systemd service. Options are `simple, exec, forking, oneshot, dbus, notify and idle`. (more info here)
* `Restart`:- This is another optional field but one that you will very likely use. This specifies if a service should be restarted--depending on circumstances--or not. The available options are `no, on-success, on-failure, on-abnormal, on-watchdog, on-abort and always`.

**The [Install] section**

The Install section, as the name says, handles the installation of a systemd service/unit file. This is used when you run either `systemctl enable` and `systemctl disable` command for enabling or disabling a service.

Below are the fields the Install section has:

* `WantedBy`:- This is similar to the `After` and `Before` fields, but the main difference is that this is used to specify systemd-equivalent "runlevels". 
    * The `default.target` is when all the system initialization is complete--when the user is asked to log in. Most user-facing services (like Apache, cron, GNOME-stuff, etc.) use this target.
* `RequiredBy`:- This field might feel very similar to `WantedBy`, but the main difference is that this field specifies hard dependencies. Meaning, if a dependency, this service will fail.

[good link](https://www.freedesktop.org/wiki/Software/systemd/)


**Different Commands**

* `sudo systemctl daemon-reload` : to tell systemd to read our service file
* `systemctl start test-app.service` : To start/activate the service, run the systemctl command as follows:
* `systemctl status test-app.service` : To check if the service is running or not, issue the systemctl command as shown.
* `systemctl enable test-app.service`: To enable the service to start at system boot, use the systemctl enable command. 
* `systemctl is-enabled test-app.service` : TO check if service is enabled or not
* `systemctl enable --now test-app.service`: you can also enable and start the service at the same time as shown.
* `systemctl stop test-app.service` : To stop/deactivate the service, run the systemctl stop command.
* `systemctl restart test-app.service` : To restart the service, run the systemctl restart command
* `systemctl disable test-app.service`:
* `systemctl is-disabled test-app.service`
* `systemctl disable --now test-app.service`: can disable and stop it at the same time as shown.

**Example**

```
[Unit]
Description=Gunicorn daemon for serving test-app
After=network.target

[Service]
User=root
Group=root
WorkingDirectory=/apps/test-app/
Environment="PATH=/apps/test-app/bin"
ExecStart=/apps/test-app/bin/gunicorn --workers 9  -t 0  --bind 127.0.0.1:5001 -m 007 wsgi:app --log-level debug --access-logfile /var/log/gunicorn/test_app_access.log --error-logfile /var/log/gunicorn/test_app_error.log
ExecReload=/bin/kill -s HUP $MAINPID
RestartSec=5

[Install]
WantedBy=multi-user.target
```

`Note: Make sure to enable the service, so that it can be restarted at reboot`

echo 1048576 > /proc/sys/fs/inotify/max_user_watches 
/etc/init.d/apache2 restart 
service apache2 start

sudo service mysql start

mysql -u root -p


#!/bin/bash

# Script para configurar rsync

# Ejecutar en un nodo y pasarle la IP del otro nodo a vincular como argumento


sudo su
mkdir /var/www/

exec rsync -avzhie "ssh" vagrant@$1:/var/www/ /var/www/


# Crontab que lo ejecuta cada minuto

echo "* * * * *     root    rsync -avzhie 'ssh' vagrant@$1:/var/www/ /var/www/" >> /etc/crontab
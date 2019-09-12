#!/bin/bash


# Script para configurar nginx como un balanceador

# Ejecutar solo en el nodo loadbalancer


sudo su
cp /etc/nginx/nginx.conf /etc/nginx/nginxBK.conf

echo '
        user www-data;
        worker_processes 4;
        pid /run/nginx.pid;

        events {
                worker_connections 768;
                # multi_accept on;
        }


        http {

                upstream servidores {
                        server 192.168.10.10;
                        server 192.168.10.11;
                        server 192.168.10.12;
                }

                server {
                        listen 80;

                        location / {
                                proxy_pass http://servidores;
                        }

                }
        }' > /etc/nginx/nginx.conf

service nginx restart

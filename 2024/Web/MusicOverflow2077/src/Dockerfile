FROM php:7.4-apache

WORKDIR /var/www/html

COPY . .

RUN echo "display_errors = Off" >> /usr/local/etc/php/php.ini && \
    echo "log_errors = On" >> /usr/local/etc/php/php.ini && \
    echo "error_reporting = E_ALL & ~E_WARNING" >> /usr/local/etc/php/php.ini



RUN sed -i "s/nice/$(cat /dev/urandom | tr -dc "a-zA-Z0-9" | head -c 10)/g" index.php
EXPOSE 80
COPY docker-entrypoint.sh /docker-entrypoint.sh
ENTRYPOINT [ "/docker-entrypoint.sh" ]

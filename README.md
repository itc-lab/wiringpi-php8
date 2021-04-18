WiringPi-php8
========
php8 WiringPi extension

Update WiringPi
========
```
cd /tmp
wget https://project-downloads.drogon.net/wiringpi-latest.deb
dpkg -i wiringpi-latest.deb
```

Building
========
```
apt-get install php8.0-dev
phpize
./configure
make
make install
```
/etc/php/8.0/apache2/conf.d/wiringpi.ini
```
extension=wiringpi.so
```
/etc/php/8.0/cli/conf.d/wiringpi.ini
```
extension=wiringpi.so
```

todo
```
sudo adduser www-data i2c
sudo adduser www-data spi
sudo adduser www-data gpio
```

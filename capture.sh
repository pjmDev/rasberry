date
while [ 1 ]
do
	dd=`date +%Y%m%d%H%M%S`
	raspistill -o /home/pi/cctv/data/capture/$dd.jpg -w 640 -h 480 -t 1 -cfx 128:128 -n
	cp  /home/pi/cctv/data/last.jpg /home/pi/cctv/data/prev.jpg
	cp  /home/pi/cctv/data/capture/$dd.jpg /home/pi/cctv/data/last.jpg

	/home/pi/cctv/picture/comp /home/pi/cctv/data/last.jpg /home/pi/cctv/data/prev.jpg
	sleep 3
done
date

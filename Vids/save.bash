#! /bin/bash
for ((a=0; a <= 10 ; a++))
do
   ffmpeg  -framerate 15 -t 00:00:10.0 -r 15 -i /dev/video0 $a.mp4
done



ffmpeg -i /dev/video0 -map 0 -codec:v libx264 -codec:a copy -f ssegment  -segment_list_type hls -segment_list_size 1 -segment_list_flags +live -segment_time 10 out%03d.ts


#!/bin/bash
inputs=`ls ../rvgs/*.rvg`
outputs="../pngs-out/"
driver='driver.png'
program='process.lua'
lua='luapp5.3'

only_quad=0
quad=("parabola1"
      "parabola2"
      "parabola3"
      "parabola4"
      "parabola5"
      "parabola6"
      "parabola7"
      "quad1"
      "quad2"
      "quad3"
      "quad4")

heavy=("blue_butterfly"
       "anatomical_heart"
       "paris-30k"
       "blender_freestyle"
       "relatorio"
       "colorado"
       "contour"
       "hawaii"
       "roads"
       "inkboard")


if [[ "$1" =~ "heavy" ]]; then
    heavy=()
fi
if [[ "$1" =~ "quad" ]]; then
    only_quad=1
fi

[ ! -d $outputs ] && mkdir $outputs
rm $outputs*
START=$(date +%s.%N)
for input in $inputs
do
    filename=$(basename -- "$input")
    extension="${filename##*.}"
    filename="${filename%.*}"
    output=$outputs$filename".png" 
    if [[ $only_quad =~ 0 ]] || [[ "${quad[@]}" =~ "${filename}" ]]; then
        if [[ ! " ${heavy[@]} " =~ " ${filename} " ]]; then
            $lua $program $driver $input $output
        fi
    fi
done
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo "TOTAL TIME: $DIFF"

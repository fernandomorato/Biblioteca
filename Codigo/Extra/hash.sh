# Para usar (hash das linhas [l1, l2]):
# ./hash.sh arquivo.cpp l1 l2
# vlw Bruno :)
sed -n $2','$3' p' $1 | sed '/^#w/d' | cpp -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum | cut -c-6
# Jurassic-Park
Част от проекти по Обектно-ориентирано програмиране

## Ферма за динозаври
динозаврите могат да са няколко вида:
 - месоядни
 - тревопасни
 - водни
 - летящи

те не съжителстват заедно, затова трябва да са разделени

необходимо е да има достатъчно храна за всички

необходимо е да има достатъчно персонал в парка, за да се грижат за всички.

Всеки динозавър се характеризира чрез
 - име
 - пол 
 - ера (триас, креда или юра) 
 - разред  (тревопасен, месояден, летящ или воден)
 - вид (плезиозавър, бронтозавър, тиранозавър и т.н.)
 - храна (трева, месо или риба)

Те са разпределени в клетки, като заедно могат да съжителстват единствено животни от една ера и един разред (но не задължително от един вид). Съответно всяка клетка  има подходящ климат - сухоземен, въздушен или воден. Има малки клетки (за едно животно), средни (за 3 животни) и големи (до 10 животни). Важна информация за клетката е:
 - размер 
 - климат
 - животни, които я обитават
 - ера на животните вътре (ако има такива)
 
В нашия зоопарк отначало има произволно количество клетки и без никакви животни. Ново животно може да се приеме, ако има подходяща клетка за него с празно място в нея. Ако няма, то такава може да бъде построена, посочвайки съответния климат и размер. 

системата за управление на зоопарка може да:
 - приема ново животно
 - строи нова клетка
 - премахва вече налично животно
 - зарежда склада с храна
 
 
### Забележки:

В началото клетките за динозаврите са случайно генерирани и като брой, и като вид.

При затваряне на програмата информацията не се губи. 

Летящите динозаври са в по-голямата си част хищни :)

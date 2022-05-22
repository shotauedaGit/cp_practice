$comment = "write_down_comment"
$test_msg = "ak9_local_test"
$loop = 1

g++ AHC008_local.cpp

for ($i=0; $i -lt $loop; $i++){
    #0       1  2        3
    .\a.exe $i $comment $test_msg
}
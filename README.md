
それぞれを別の実行ファイルに
- gcc shm_write_float.c -o shm_write
- gcc shm_read_float.c -o shm_read
  
のようにコンパイルすること

また、aoti(要stdlib)はエラー処理ができるstrtolに置き換え推奨

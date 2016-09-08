<?php
//ambil koneksi dari koneksi.php
include "koneksi.php";

// Perintah untuk menampilkan data
$queri="Select * From th" ;  //menampikan SEMUA data dari tabel th

$hasil=MySQL_query ($queri);    //fungsi untuk SQL

// perintah untuk membaca dan mengambil data dalam bentuk array
while ($data = mysql_fetch_array ($hasil)){
$id = $data['id'];
 echo "	 
		id_no :  ".$data['id_no']."
		id_getway: ".$data['id_getway']." 
		id_paring : ".$data['id_paring']."  
		jenis : ".$data['jenis']." 
		------------------------------------- 
		";
		 
}
echo " Berhasil Mengambil data dari database";
?>  

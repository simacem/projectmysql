<?php
include "koneksi.php";

$id = $_POST['id_no'];
$id_getway=$_POST['id_getway'];
$id_paring = $_POST['id_paring'];
$jenis = $_POST['jenis'];


$query_update="update th SET id_getway='$id_getway', id_paring='$id_paring', jenis='$jenis' WHERE id_no='$id'";
$update = mysql_query($query_update);

if($update)
    {
    include("redirectview.php");
    }

else
    {
    echo "Gagal update ... ";
    echo "<META HTTP-EQUIV=Refresh CONTENT='2; URL=lihatdata.php'>";
    }


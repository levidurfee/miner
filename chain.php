<?php

$start = "levidurfee";
$hash = "";
$difficulty = 4;

for($i=0; $i<5; $i++) {
	$output = [];
	$zs = getZeroes($difficulty);
	$seed = $start . time();
	$run = "./build/main " . $seed.$hash . " " . $zs;
	exec($run, $output);
	$nonce = $output[0];
	$hash = $output[1];
	echo $i .' '. $hash . "\n";
	if($i % 200 == 0) {
		$difficulty++;
	}
	file_put_contents('output.txt', $seed .','. $nonce . ',' . $hash . "\n", FILE_APPEND);
}

function getZeroes($num) {
	$z = "";
	for($i=0; $i<$num; $i++) {
		$z .= "0";
	}
	return $z;
}

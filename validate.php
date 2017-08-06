<?php
// validate

$data = file_get_contents('output.txt');
$lines = explode("\n", $data);
array_pop($lines);
$hash = "";
for($i=0; $i<count($lines); $i++) {
	$line_data = explode(",", $lines[$i]);
	$input = $line_data[0];
	$nonce = $line_data[1];
	$chash = $line_data[2];

	//echo $input.$hash.$nonce . "\n";
	$hash = hash('sha512', $input.$hash.$nonce);
	//echo $hash . "\n";
	//echo $chash . "\n";
	if($hash == $chash) {
		echo '.';
	} else {
		echo 'x';
	}
	//echo "\n";
}

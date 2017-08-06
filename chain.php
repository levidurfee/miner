<?php

$data = "levi";
$nonces = getChainData();
$hash = "";

for($i=0; $i<count($nonces); $i++) {
	$next = $data . $hash . $nonces[$i];
	$hash = strtoupper(hash('sha512', $next));
	echo $hash . "\n";
}

function getChainData($filename = 'chain.txt') {
	$raw = file_get_contents($filename);
	$lines = explode("\n", $raw);
	return $lines;
}

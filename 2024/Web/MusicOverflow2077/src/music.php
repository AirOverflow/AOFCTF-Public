<?php



class DownloadFile {
	function __construct($name) {
		$this->name = '/var/www/html/music/'.$name;
		$this->download = false;
		if (preg_match("/\.\.\//",$this->name)){
			$this->name = preg_replace("/\.\/\//", ".", $this->name);
		}
		if (file_exists($this->name)){
			$this->download = true;
		}else{
			echo "This song ".$this->name." does not exist!";
		}

	}

	function __destruct(){
		if ($this->download){
			$file = $this->name;
			header("Content-Disposition: attachment; filename=\"" . basename($file) . "\"");
			header("Content-Length: " . filesize($file));
			header("Content-Type: application/octet-stream;");
			readfile($file);
			exit();
		}
	}
}

if(isset($_GET['song'])){
	$file = trim($_GET['song']);
	new DownloadFile($file);
}
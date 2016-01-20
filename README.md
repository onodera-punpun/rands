rands command
======================
output random string ランダムな文字列を出力する

options オプション
------
	-l length    specifies the string length 出力する文字列の長さを指定
	-aAnsS
		a    exclude small letters アルファベット小文字を除く
		A    exclude capital letters アルファベット大文字を除く
		n    exclude numbers 数字を除く
		s    exclude symbols 記号を除く
		S    include white spaces スペースを含む
	-h    show help ヘルプ
default execute "rands -l 8" デフォルトでは，rands -l 8 を実行

installing インストール
------
	sh install.sh
this behavior would require or create a directory "/Users/$USER/bin"  
インストールする際に，/Users/$USER/bin というディレクトリが無ければ作成します

Command is created in the "/Users/$USER/bin" , then create a symbolic link to the "/usr/local/bin"  
コマンドは /Users/$USER/bin に生成されて，/usr/local/bin にシンボリックリンクを作成します

uninstalling アンインストール
------
	sh uninstall.sh
remove symbolic link "/usr/local/bin/rands" and file "/Users/$USER/bin/rands"  
シンボリックリンクと実行ファイルを消去します
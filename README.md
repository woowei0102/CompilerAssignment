# 編譯器Compiler題目練習

## 介紹
在進入實驗室前，學長要求盡量把這三份BOSS Attack完成，是為了之後當Compiler助教作準備，而也順利完成。

## Boss Attack
這裡簡單敘述題目內容，如果要詳細了解0可透過`Boss Attack資料夾`看到各個題目。
### 01 
Compiler中的Scanner和Parser，Scanner會逐個逐個字元讀進來並且在`適當時候`把字元合成一組詞語供後邊的Parser做其他處理工作，Parser對語法(Grammar)會進行分析，而它的作用進行語法檢查、並構建由輸入的tokens組成的資料結構（一般是語法分析樹、抽象語法樹等層次化的資料結構）。

這份作業是要實作一個四則運算計算機，針對各種運算式透過Scanner來判別數字(`([1-9][0-9]*)|0`)、加(`+`)、減(`-`)、乘(`*`)、除(`/`)、左括號( `(` )、右括號( `)` )，之後將這些tokens輸入至Parser中會輸出的一個Parser Tree，透過此Parser Tree進行前序追蹤方式輸出每個字詞。



### 02 
透過lex進行對資料切分成各個tokens，進而透過這些tokens可作出排版和轉換文字等等功能。而還會作一個First，是在建構Parser時的重要資訊之一，當同時符合多條規則時，能夠用來決定要選擇哪一條規則進行展開。

這份作業有三個題目:
1. 將程式碼進行排版
2. 輸入一連串的指令，針對裡面的tokens進行轉換並輸出
3. 實作First Set

### 03
透過lex和yacc作出跟Compiler中的Scanner和Parser一樣功能。

這份作業有兩個題目:
1. Matrix Calculator: 給予一個矩陣運算式並給輸出解答，如果有運算式寫錯，會根據運算式中的第幾個字給予使用者回報
2. Stack-based machine: 針對stack常見的指令順序給予輸出結果，例如:load、delete等，如果沒有符合stack指令以及語法，便會給使用者錯誤回報

## 結論
寫這三份題目時，也必須好好看過一遍Compiler教材，在這過程理解到Compiler一些知識，讓我受益良多。

## 相關文件
* [Compiler教材](https://drive.google.com/drive/folders/1iH3WPOQ0KTD66GZC6poKZHHa4K8K5nGW?fbclid=IwAR3CddH-curgrWu6lSLwJwzKEa1Au5x5S8XVtEA0C8Z75-CoDmgyvF23TX8)

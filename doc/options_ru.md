#

## ��騥 ��ࠬ����

� �⮬ ࠧ���� �� ��ᬮ�ਬ �������� ��� �ᯮ��㥬� ��樨 ��� ����᪠ `�᭮����` �ணࠬ�� � �����ﬨ LLaMA:

- `-m FNAME, --model FNAME`: ������ ���� � 䠩�� ������ LLaMA (���ਬ��, `models/7B/ggml-model.bin`).
- `-i, --interactive`: ������� �ணࠬ�� � ���ࠪ⨢��� ०���, �� �������� ��� ������� ����� ������� � ������� �⢥�� � ०��� ॠ�쭮�� �६���.
- `-ins, --instruct`: ������� �ணࠬ�� � ०��� ������権, �� �ᮡ���� ������� �� ࠡ�� � �����ﬨ ��쯠��.
- `-n N, --n-predict N`: ��⠭���� ������⢮ ⮪���� ��� �ண����஢���� �� �����樨 ⥪��. ����ன�� �⮣� ���祭�� ����� �������� �� ����� ᣥ���஢������ ⥪��.
- `-c N, --ctx-size N`: ��⠭���� ࠧ��� ���⥪�� �ਣ��襭��. ���祭�� �� 㬮�砭�� ࠢ�� 512, �� ������ LLaMA �뫨 ����஥�� � ���⥪�⮬ 2048, �� ���ᯥ�� ���訥 १����� �� ����� ���⥫쭮� �����/�����᪮� �뢮��.

## ���᪠��� �����

�ணࠬ�� "main" �।��⠢��� ��᪮�쪮 ᯮᮡ�� ����������⢨� � �����ﬨ LLaMA � ������� ���᪠��� �����:

- `--prompt �����������`: �।��⠢�� �ਣ��襭�� �����।�⢥��� � ����⢥ ��ࠬ��� ��������� ��ப�.
- `--file FNAME`: ������ 䠩�, ᮤ�ঠ騩 �ਣ��襭�� ��� ��᪮�쪮 �ਣ��襭��.
- `--interactive-first`: ������� �ணࠬ�� � ���ࠪ⨢��� ०��� � �ࠧ� �������� �����. (���஡��� �� �⮬ ����.)
- `--random-prompt`: ��筨� � ࠭������஢������ �ਣ��襭��.

## ����������⢨�

�ணࠬ�� "main" �।������ ���⮩ ᯮᮡ ����������⢨� � �����ﬨ LLaMA, �������� ���짮��⥫� ���� ��ᥤ� � ०��� ॠ�쭮�� �६��� ��� �।��⠢���� ������樨 ��� �믮������ �������� �����. ���ࠪ⨢�� ०�� ����� ���� ����饭 � �ᯮ�짮������ ࠧ����� ��権, ������ "--interactive", "--interactive-first` � `--instruct`.

� ���ࠪ⨢��� ०��� ���짮��⥫� ����� ���⢮���� � �����樨 ⥪��, ����� ᢮� ����� �� �६� �����. ���짮��⥫� ����� � �� �६� ������ "Ctrl+C", �⮡� ��⠢��� � ����� ᢮� �����, � ��⥬ ������ "Return", �⮡� ��ࠢ��� �� � ������ LLaMA. �⮡� ��ࠢ��� �������⥫�� ��ப� ��� �����襭�� �����, ���짮��⥫� ����� �������� ⥪���� ��ப� ���⭮� ��ᮩ ��⮩ (`\`) � �த������ ����.

### ��ࠬ���� ����������⢨�

- `-i, --interactive`: ����� �ணࠬ�� � ���ࠪ⨢��� ०���, ��������騩 ���짮��⥫� ���⢮���� � ��ᥤ�� � ०��� ॠ�쭮�� �६��� ��� ������ ������� ������樨 ������.
- `--interactive-first`: ������� �ணࠬ�� � ���ࠪ⨢��� ०��� � ���������� �������� ����� ���짮��⥫��, �०�� 祬 ��稭��� ������� ⥪��.
- `-ins, --instruct`: ������� �ணࠬ�� � ०��� ������樨, ����� ᯥ樠�쭮 ࠧࠡ�⠭ ��� ࠡ��� � �����ﬨ Alpaca, ����� �ॢ��室�� �ࠢ������ � ����砬�, �᭮����묨 �� ��������� ���짮��⥫�.
- `--color`: ������ 梥⭮� �뢮�, �⮡� ���㠫쭮 ࠧ����� ���᪠���, ������� ���짮��⥫��, � ᣥ���஢���� ⥪��.

������� � �ᯮ���� �� ��ਠ��� ����������⢨�, �� ����� ᮧ������ 㢫���⥫�� � �������� ����������⢨� � �����ﬨ LLaMA, �������� ����� ᮧ����� ⥪�� � ��訬 ������� ���ॡ�����.

### ����� ���᪠���

����� �ਣ��襭�� - �� ���� ᯮᮡ ᮧ���� ����⫥��� �� � ������� LLaMA, �ਮ�⠭������� ������� ⥪�� �� �����㦥��� ��।������� ⥪�⮢�� ��ப:

- `-r �����������, --reverse-prompt �����������`: ������ ���� ��� ��᪮�쪮 ������ �ਣ��襭��, �⮡� �ਮ�⠭����� ������� ⥪�� � ��४������� � ���ࠪ⨢�� ०��. ���ਬ��, `-r "���짮��⥫�:"` ����� �ᯮ�짮���� ��� ������ � ࠧ������ ��直� ࠧ, ����� ����㯠�� ��।� ���짮��⥫� �������. �� �������� ᮧ���� ����� ���ࠪ⨢�� � ࠧ������ ����. ������ ���⭮� �ਣ��襭�� �� ࠡ�⠥�, �᫨ ��� �����稢����� �஡����.

�⮡� �८������ �� ��࠭�祭��, �� ����� �ᯮ�짮���� 䫠� "--in-prefix", �⮡� �������� �஡�� ��� ��� ��㣨� ᨬ���� ��᫥ ���⭮�� �ਣ��襭��.

### In-Prefix

���� `--in-prefix` �ᯮ������ ��� ���������� ��䨪� � ��訬 ������� �����, � ����� ��।�, �� �ᯮ������ ��� ��⠢�� �஡��� ��᫥ ���⭮�� �ਣ��襭��. ��� �ਬ�� ⮣�, ��� �ᯮ�짮���� 䫠� `--in-prefix` � ��⠭�� � 䫠��� `--reverse-prompt':

``sh
./main -r "���짮��⥫�:" --in-prefix " "
```

### �-���䨪�

���� `--in-suffix` �ᯮ������ ��� ���������� ���䨪� ��᫥ ��襣� �����. �� ������� ��� ���������� ����� "����魨�:" ��᫥ ����� ���짮��⥫��. �� ���������� ��᫥ ᨬ���� ����� ��ப� (`\n`), ����� ��⮬���᪨ ���������� � ����� ���짮��⥫�᪮�� �����. ��� �ਬ�� ⮣�, ��� �ᯮ�짮���� 䫠� `--in-suffix` � ��⠭�� � 䫠��� `--reverse-prompt':

``sh
./main -r "���짮��⥫�:" --�-��䨪� " " --�-���䨪� "����⥭�:"
```

### ����� ������権

����� ������権 �ᮡ���� ������� �� ࠡ�� � �����ﬨ Alpaca, ����� �।�����祭� ��� �믮������ ������権 ���짮��⥫� �� �믮������ �������� �����:

- `-ins, --instruct`: ������ ०�� ������権, �⮡� �ᯮ�짮���� ���������� ������� Alpaca �� �믮������ ����� �� �᭮�� �।��⠢������ ���짮��⥫�� ������権.

��孨�᪠� ��⠫�: ������� ���짮��⥫�� ����� ����� ����७��� ��䨪� ���⭮�� �ਣ��襭�� (��� "### ��������:" �� 㬮�砭��), �� ����� ᫥��� "### �⢥�:" (�� �᪫�祭��� ��砥�, ����� �� ���� �������� Return ��� �����-���� �������� ������, �⮡� �த������ �����஢��� ����� ������ �⢥�).

������� � �ᯮ���� �� ��ਠ��� ����������⢨�, �� ����� ᮧ������ 㢫���⥫�� � �������� ����������⢨� � �����ﬨ LLaMA, �������� ����� ᮧ����� ⥪�� � ��訬 ������� ���ॡ�����.

## ��ࠢ����� ���⥪�⮬

�� �६� �����樨 ⥪�� ������ LLaMA ����� ��࠭�祭�� ࠧ��� ���⥪��, �� ����砥�, �� ��� ����� ���뢠�� ⮫쪮 ��।������� ������⢮ ⮪���� �� �室���� � ᣥ���஢������ ⥪��. ����� ���⥪�� ����������, ������ ����७�� ��१���㦠����, ��⥭樠�쭮 ���� �������� ���ଠ�� �� ��砫� ࠧ����� ��� ������権. ��ࠬ���� �ࠢ����� ���⥪�⮬ �������� �����ন���� �����뢭���� � ᮣ��ᮢ������� � ⠪�� ������.

### ������ ���⥪��

��ࠬ��� `--ctx-size` �������� ������ ࠧ��� ���⥪�� �����, �ᯮ��㥬��� �����ﬨ LLaMA �� �����樨 ⥪��. ����訩 ࠧ��� ���⥪�� �������� ������ ���� �������� � �����஢��� �⢥�� ��� ����� ���⥫쭮�� ����� ��� ࠧ����஢.

- `-c N, --ctx-size N`: ��⠭���� ࠧ��� ���⥪�� ����� (�� 㬮�砭��: 512). ������ LLaMA �뫨 ����஥�� � ���⥪�⮬ 2048, ����� ���� ������訥 १����� �� ����� ���⥫쭮� �����/�����᪮� �뢮��. ������ 㢥��祭�� ࠧ��� ���⥪�� ᢥ�� 2048 ����� �ਢ��� � ���।᪠�㥬� १���⠬.

### �����祭�� ࠧ��� ���⥪��

������� �筮 ����஥��� ������ 㢥��稫� ����� ���⥪�� �� ��� ����⠡�஢���� RoPE. ���ਬ��, �᫨ ��室��� �।���⥫쭮 ���祭��� ������ ����� ����� ���⥪�� (���ᨬ����� ����� ��᫥����⥫쭮��) 4096 (4k), � �筮 ����஥���� ������ ����� 32k. �� �����樥�� ����⠡�஢����, ࠢ�� 8, � �� ������ ࠡ����, �᫨ ��⠭����� 㪠������ ��� ���祭�� "--ctx-size" ࠢ�� 32768 (32k), � `--rope-scale` ࠢ�� 8.

- `--rope-scale N`: ��� N - �����樥�� ��������� ����⠡�஢����, �ᯮ��㥬� � �筮 ����஥���� ������.

### ���࠭�� ���᪠���

��ࠬ��� `--keep` �������� ���짮��⥫� ��࠭��� ��室��� �ਣ��襭��, ����� ������ ��室�� �� ���⥪��, ���ᯥ稢�� ��࠭���� �裡 � ��室��� ������樥� ��� ⥬�� ࠧ�����.

- `--keep N`: ������ ������⢮ ⮪���� �� ��室���� �ਣ��襭��, ����� ����室��� ��࠭���, ����� ������ ���� ᢮� ����७��� ���⥪��. �� 㬮�砭�� �� ���祭�� ࠢ�� 0 (�� ����砥�, �� ⮪��� �� ��࠭�����). �ᯮ���� `-1`, �⮡� ��࠭��� �� ⮪��� �� ��ࢮ��砫쭮�� �ਣ��襭��.

�ᯮ���� ��ࠬ���� �ࠢ����� ���⥪�⮬, ⠪�� ��� `--ctx-size` � `--keep`, �� ����� �����ন���� ����� ᮣ��ᮢ����� ����������⢨� � �����ﬨ LLaMA, ��࠭����, �� ᣥ���஢���� ⥪�� ��⠥��� ᮮ⢥�����騬 ��室���� �ਣ��襭�� ��� �������.

## ����� �����樨

������騥 ��樨 ��������� ��� �ࠢ���� ����ᮬ �����樨 ⥪�� � �筮 ����ࠨ���� ࠧ����ࠧ��, �ॠ⨢����� � ����⢮ ������㥬��� ⥪�� � ᮮ⢥��⢨� � ��訬� ���ॡ����ﬨ. ���㫨��� �� ��樨 � ��ᯥਬ������ � ࠧ���묨 ��������ﬨ ���祭��, �� ����� ���� ������訥 ����ன�� ��� ��襣� �����⭮�� ���� �ᯮ�짮�����.

### ������⢮ ⮪���� ��� �ண����஢����

- `-n N, --n-predict N`: ��⠭���� ������⢮ ⮪���� ��� �ண����஢���� �� �����樨 ⥪�� (�� 㬮�砭��: 128, -1 = ��᪮��筮���, -2 = �� ���������� ���⥪��)

��ࠬ��� `--n-predict` �ࠢ��� ������⢮� ⮪����, ������㥬�� ������� � �⢥� �� ����� �����. ���㫨��� �� ���祭��, �� ����� ������ �� ����� ������㥬��� ⥪��. ����� ��᮪�� ���祭�� �ਢ���� � ����� �������� ⥪���, � � �६� ��� ����襥 ���祭�� �ਢ���� � ����� ���⪮�� ⥪���.

���祭�� -1 �������� �����஢��� ��᪮���� ⥪��, ���� �᫨ � ��� ����筮� ���⥪�⭮� ����. ����� ���⥪�⭮� ���� ����������, ������� �� ����� ࠭��� ⮪���� (�������� ⮪���� ��᫥ `--n-keep`) ���� ���襭�. ��⥬ ���⥪�� ������ ���� ����୮ �業��, �०�� 祬 ������� ᬮ��� �������������. � ������ ������� �/��� ������ ���⥪���� ����� �� �ਢ���� � ����⥫쭮� ��㧥 � �뢮��.

�᫨ ��㧠 ������⥫쭠, ���祭�� -2 ���������� ��⠭���� �������, ����� ���⥪�� �㤥� ��������.

����� �⬥���, �� ᣥ���஢���� ⥪�� ����� ���� ���� 㪠������� ������⢠ ⮪����, �᫨ ����砥��� ⮪�� ���� ��᫥����⥫쭮�� (EOS) ��� ����� ���⭮�� �맮��. � ���ࠪ⨢��� ०��� ������� ⥪�� �ਮ�⠭����������, � �ࠢ����� �����頥��� ���짮��⥫�. � �����ࠪ⨢��� ०��� �ணࠬ�� ���������. � ����� ����� ������� ⥪�� ����� �४������ �� ���⨦���� 㪠������� ���祭�� `n-�ண���`. �᫨ �� ���, �⮡� ������ �த������ ࠡ����, ���� �� ᮧ����� ����� ��᫥����⥫쭮�� ᠬ����⥫쭮, �� ����� �ᯮ�짮���� ��ࠬ��� `--ignore-eos`.

### ���������

- `--temp N`: ��ॣ㫨��� ��砩����� ������㥬��� ⥪�� (�� 㬮�砭��: 0.8).

��������� - �� ����௠ࠬ���, ����� �ࠢ��� ��砩������ ������㥬��� ⥪��. �� ����� �� ��।������ ����⭮�⥩ ��室��� ⮪���� ������. ����� ��᮪�� ⥬������ (���ਬ��, 1,5) ������ ��室�� ����� ����� ��砩�묨 � �ॠ⨢�묨, � � �६� ��� ����� ������ ⥬������ (���ਬ��, 0,5) ������ ��室�� ����� ����� 楫����ࠢ����묨, ���ନ��஢���묨 � ����ࢠ⨢�묨. ���祭�� �� 㬮�砭�� ࠢ�� 0.8, �� ���ᯥ稢��� ������ ����� ��砩������ � ���ନ������. � �ࠩ��� ��砥, ⥬������, ࠢ��� 0, �ᥣ�� �㤥� �롨��� �������� ������ ᫥���騩 ⮪��, �� �ਢ���� � ������� १���⠬ �� ������ ����᪥.

�ਬ�� �ᯮ�짮�����: `--temp 0.5`

### ���� �� �����

- `--repeat-penalty N`: ��ࠢ��� ����७��� ��᫥����⥫쭮�⥩ ⮪���� � ᣥ���஢����� ⥪�� (�� 㬮�砭��: 1.1).
- `--repeat-last-n N`: ��᫥���� n ⮪����, ����� ����室��� ���뢠�� ��� ��������� �� ����७�� (�� 㬮�砭��: 64, 0 = �⪫�祭�, -1 = ctx-ࠧ���).
- `--no-penalize-nl`: �⪫��� ���������� ��� ⮪���� ����� ��ப� �� �ਬ������ ���� �� ����७��.

���� "repeat-penalize" �������� �।������ �����஢���� ������� �������饣��� ��� ����⮭���� ⥪��. ����� ��᮪�� ���祭�� (���ਬ��, 1.5) �㤥� ����� ��ண� �����뢠�� �� ����७��, � � �६� ��� ����� ������ ���祭�� (���ਬ��, 0.9) �㤥� ����� ���. ���祭�� �� 㬮�砭�� - 1.1.

��ࠬ��� `repeat-last-n` �ࠢ��� ������⢮� ⮪���� � ���ਨ, ����� ᫥��� ���뢠�� ��� ��������� �� ����७��. ����襥 ���祭�� �㤥� �⮡ࠦ����� ����� � ᣥ���஢����� ⥪��, �⮡� �।������ ����७��, � � �६� ��� ����襥 ���祭�� �㤥� ���뢠�� ⮫쪮 ��᫥���� ⮪���. ���祭�� 0 �⪫�砥� ����, � ���祭�� -1 ��⠭�������� ������⢮ ⮪����, �������� ࠢ�묨 ࠧ���� ���⥪�� (`ctx-size`).

�ᯮ���� ���� `--no-penalize-nl`, �⮡� �⪫���� ���� �� ��ॢ�� ��ப� �� �ਬ������ ���� �� �����. �� ���� �ᮡ���� ������� ��� ᮧ����� ࠧ����஢ � ��, ��������, ����, ������ ��� ��� ⥪��, ��� ᨬ���� ��ॢ��� ��ப� ����� ����⥫��� ஫� � ������� � �ଠ�஢����. �⪫�祭�� ���䮢���� �� ��ॢ�� ��ப� �������� ��࠭��� ����⢥��� ��⮪ � �।���������� �ଠ�஢���� � ��� �������� ����� �ᯮ�짮�����.

�ਬ�� �ᯮ�짮�����: `--repeat-penalty 1.15 --repeat-last-n 128 --no-penalize-nl`

### �롮ઠ Top-K

- `--top-k N`: ��࠭���� �롮� ᫥���饣� ⮪��� K �������� �����묨 ⮪����� (�� 㬮�砭��: 40).

�롮ઠ Top-k - �� ��⮤ �����樨 ⥪��, ����� �롨ࠥ� ᫥���騩 ⮪�� ⮫쪮 �� k �������� ������� ⮪����, �।᪠������ �������. �� �������� ᭨���� �� �����樨 ����������� ��� �����᫥���� ⮪����, �� ⠪�� ����� ��࠭���� ࠧ����ࠧ�� ��室��� ������. ����� ��᮪�� ���祭�� ��� top-k (���ਬ��, 100) �㤥� ���뢠�� ����� ⮪���� � �ਢ���� � ����� ࠧ����ࠧ���� ⥪���, � � �६� ��� ����� ������ ���祭�� (���ਬ��, 10) ��।���� �������� �� �������� ������� ⮪���� � ᣥ������ ����� ����ࢠ⨢�� ⥪��. ���祭�� �� 㬮�砭�� - 40.

�ਬ�� �ᯮ�짮�����: `--top-k 30`

### �롮ઠ Top-P

- `--top-p N`: ��࠭���� �롮� ᫥���饣� ⮪��� ���������⢮� ⮪���� � ����⨢��� ����⭮���� ��� ��ண����� ���祭�� P (�� 㬮�砭��: 0,9).

�롮ઠ Top-p, ⠪�� �����⭠� ��� �롮ઠ nucleus, - �� �� ���� ��⮤ �����樨 ⥪��, ����� �롨ࠥ� ᫥���騩 ⮪�� �� ���������⢠ ⮪����, ����� ����� ����� ᮢ��㯭�� ����⭮��� �� ����� p. ��� ��⮤ ���ᯥ稢��� ������ ����� ࠧ����ࠧ��� � ����⢮�, ���뢠� ��� ����⭮�� ⮪����, ⠪ � ������⢮ ⮪���� ��� �롮ન. ����� ��᮪�� ���祭�� top-p (���ਬ��, 0,95) �ਢ���� � ����� ࠧ����ࠧ���� ⥪���, � � �६� ��� ����� ������ ���祭�� (���ਬ��, 0,5) �ਢ���� � ᮧ����� ����� �䮪��஢������ � ����ࢠ⨢���� ⥪��. ���祭�� �� 㬮�砭�� ࠢ�� 0,9.

�ਬ�� �ᯮ�짮�����: `--top-p 0.95`

### �������쭠� �롮ઠ P

- `--min-p N`: ��⠭�������� ��������� ��ண ������� ����⭮�� ��� �롮� ⮪��� (�� 㬮�砭��: 0,05).

��⮤ �롮ન Min-P �� ࠧࠡ�⠭ ��� ����ୠ⨢� Top-P � ���ࠢ��� �� ���ᯥ祭�� ������ ����⢠ � ࠧ����ࠧ��. ��ࠬ��� *p* �।�⠢��� ���������� ����⭮��� ⮣�, �� ⮪�� �㤥� ��ᬮ�७, �⭮�⥫쭮 ����⭮�� �������� ����⭮�� ⮪���. ���ਬ��, �� *p*=0,05 � �������� ����⭮� ⮪���, ����饬 ����⭮��� 0,9, ������ � ���祭��� ����� 0,045 ��䨫��஢뢠����.

�ਬ�� �ᯮ�짮�����: `--min-p 0,05`

### �롮ઠ ��� 墮�� (TFS)

- `--tfs N`: ������� �롮�� ��� 墮�� � ��ࠬ��஬ z (�� 㬮�砭��: 1.0, 1.0 = �⪫�祭�).

�롮ઠ ��� 墮�⮢ (TFS) - �� ��⮤ �����樨 ⥪��, ���ࠢ����� �� 㬥��襭�� ���ﭨ� ����� ������� ⮪����, ����� ����� ���� ����� ५�����묨, ����� �吝묨 ��� �����᫥��묨, �� ��室�� �����. �������筮 Top-P, �� ��⠥��� �������᪨ ��।����� �᭮���� ���� �������� ������� ⮪����. �� TFS ��䨫��஢뢠�� ������ �� �᭮�� ��ன �ந������� �� ����⭮�⥩. ���������� ⮪���� �४�頥��� ��᫥ ⮣�, ��� �㬬� ����� �ந������� ���⨣��� ��ࠬ��� z. �����: TFS ᬮ���, ��� ����� 㬥������� ����⭮�� ⮪����, � ��ᥪ��� 墮�� ����������� ⮪����, �ᯮ���� ��ࠬ��� z. ������ ���祭�� ��� z ��室���� � ��������� �� 0,9 �� 0,95. ���祭�� 1,0 �㤥� ������� �� ⮪��� �, ⠪�� ��ࠧ��, �⪫��� ��䥪� TFS.

�ਬ�� �ᯮ�짮�����: `--tfs 0,95`

### �����쭮 ⨯�筠� �롮ઠ

- `--⨯��� N`: ������� �����쭮 ⨯���� �롮�� � ��ࠬ��஬ p (�� 㬮�砭��: 1.0, 1.0 = �⪫�祭�).

�����쭮 ⨯�筠� �롮ઠ ᯮᮡ���� ᮧ����� ���⥪��㠫쭮 ᮣ��ᮢ������ � ࠧ����ࠧ���� ⥪�� ��⥬ �롮ન ���ᥬ, ����� ����� ⨯��묨 ��� �������묨 �� �᭮�� ���㦠�饣� ���⥪��. ��⠭���� ��ࠬ��� p � ��������� �� 0 �� 1, �� ����� ����஫�஢��� ������ ����� ᮧ������ �����쭮 ᮣ��ᮢ������ � ࠧ����ࠧ���� ⥪��. ���祭��, ������� � 1, �㤥� ᯮᮡ�⢮���� ����� ���⥪��㠫쭮 ᮣ��ᮢ���� ⮪����, � � �६� ��� ���祭��, ������� � 0, �㤥� ᯮᮡ�⢮���� ����� ࠧ����ࠧ�� ⮪����. ���祭��, ࠢ��� 1, �⪫�砥� �����쭮 ⨯���� �롮��.

�ਬ�� �ᯮ�짮�����: `--typical 0.9`

### �롮ઠ Mirostat

- `--mirostat N`: ������� �롮�� Mirostat, ����஫���� ��⠭��� �� �����樨 ⥪�� (�� 㬮�砭��: 0, 0 = �⪫�祭�, 1 = Mirostat, 2 = Mirostat 2.0).
- `--mirostat-lr N`: ��⠭���� ᪮���� ���祭�� Mirostat, ��ࠬ��� eta (�� 㬮�砭��: 0.1).
- `--mirostat-ent N`: ��⠭���� 楫���� ���ய�� Mirostat, ��ࠬ��� tau (�� 㬮�砭��: 5.0).

Mirostat - �� ������, ����� ��⨢�� �����ন���� ����⢮ ᣥ���஢������ ⥪�� � �������� ��������� �� �६� �����樨 ⥪��. �� ���ࠢ��� �� ���⨦���� ������ ����� ᮣ��ᮢ�������� � ࠧ����ࠧ���, ������� ������⢥����� �뢮��, �맢������ �१���� ����७��� (����誨 �㪨) ��� ����᫥����⥫쭮���� (����誨 ��⠭���).

��ࠬ��� `--mirostat-lr` ��⠭�������� ᪮���� ���祭�� Mirostat (eta). ������� ���祭�� ����� �� �, ��᪮�쪮 ����� ������ ॠ����� �� ������ ��� �� ᣥ���஢������ ⥪��. ����� ������ ᪮���� ���祭�� �ਢ���� � ����� ��������� ���४�஢��, � � �६� ��� ����� ��᮪�� ᪮���� ���祭�� ᤥ���� ������ ����� ���稢�. ���祭�� �� 㬮�砭�� - `0.1`.

��ࠬ��� `--mirostat-ent` ��⠭�������� 楫���� ���ய�� Mirostat (tau), ����� �।�⠢��� �������� ���祭�� ����⠭���� ��� ᣥ���஢������ ⥪��. ����ன�� 楫���� ���ய�� �������� ����஫�஢��� ������ ����� �吝����� � ࠧ����ࠧ��� � ᣥ���஢����� ⥪��. ����襥 ���祭�� �ਢ���� � ����祭�� ����� �䮪��஢������ � �吝��� ⥪��, � � �६� ��� ����� ��᮪�� ���祭�� �ਢ���� � ����祭�� ����� ࠧ����ࠧ���� � ��⥭樠�쭮 ����� �吝��� ⥪��. ���祭�� �� 㬮�砭�� - `5.0`.

�ਬ�� �ᯮ�짮�����: `--mirostat 2 --mirostat-lr 0.05 --mirostat-ent 3.0`

### �����-ᬥ饭��

- `-l TOKEN_ID(+/-)��������, --logit-ᬥ饭�� TOKEN_ID(+/-)��������`: ������� ����⭮��� ������ ⮪��� � ᣥ���஢����� ⥪�⮢�� �����襭��.

��ࠬ��� logit bias �������� ��� ������ ����ந�� ����⭮��� ������ ��।������� ⮪���� � ᣥ���஢����� ⥪��. ������ �����䨪��� ⮪��� � ������⥫쭮� ��� ����⥫쭮� ���祭�� ᬥ饭��, �� ����� 㢥����� ��� 㬥����� ����⭮��� ᮧ����� �⮣� ⮪���.

���ਬ��, �ᯮ���� `--logit-bias 15043+1`, �⮡� 㢥����� ����⭮��� ������ ⮪��� 'Hello', ��� `--logit-bias 15043-1`, �⮡� 㬥����� ��� ����⭮���. �ᯮ���� ���祭�� ����⥫쭮� ��᪮��筮��, `--logit-bias 15043-inf` ��࠭����, �� ⮪�� `Hello` ������� �� �㤥� ᮧ���.

����� �ࠪ��� ��ਠ�⮬ �ᯮ�짮����� ����� �� ���� �।���饭�� �����樨 `\code{begin}` � `\code{end}`, ��⠭���� ⮪�� `\` (29905) �� ����⥫��� ��᪮��筮��� � ������� `-l 29905-inf`. (�� �易�� � �����࠭�������� ����� LaTeX, ����� �⮡ࠦ����� �� �뢮�� ������ LLaMA.)

�ਬ�� �ᯮ�짮�����: `--logit-bias 29905-inf`

### ��砫쭮� ���祭�� RNG

- `-s SEED, --seed SEED`: ��⠭���� ��砫쭮� ���祭�� ������� ��砩��� �ᥫ (RNG) (�� 㬮�砭��: -1, -1 = ��砩��� ��砫쭮� ���祭��).

��砫쭮� ���祭�� RNG �ᯮ������ ��� ���樠����樨 ������� ��砩��� �ᥫ, ����� ����� �� ����� �����樨 ⥪��. ��⠭���� ��।������� ��砫쭮� ���祭��, �� ����� ������� ᮣ��ᮢ���� � ���ந������� १����� �� ��᪮�쪨� ����᪠� � ��������묨 �室�묨 ����묨 � ����ன����. �� ����� ���� ������� ��� ���஢����, �⫠��� ��� �ࠢ����� ���ﭨ� ࠧ����� ��ࠬ��஢ �� ᣥ���஢���� ⥪��, �⮡� 㢨����, ����� ��� ��室����. �᫨ ��� ��砫쭮�� ���祭�� ������ ���祭�� ����� 0, �㤥� �ᯮ�짮������ ��砩��� ��砫쭮� ���祭��, �� �ਢ���� � ࠧ���� १���⠬ �� ������ ����᪥.

## ����ன�� �ந�����⥫쭮�� � ��ࠬ��஢ �����

�� ��ࠬ���� �������� ������� �ந�����⥫쭮��� � �ᯮ�짮����� ����� ������� LLaMA. ���㫨��� �� ��ࠬ����, �� ����� �筮 ����ந�� ��������� ������ � ᮮ⢥��⢨� � ����������ﬨ ��襩 ��⥬� � ������ ��⨬��쭮� �ந�����⥫쭮�� ��� ��襣� �����⭮�� ���� �ᯮ�짮�����.

### ������⢮ ��⮪��

- `-t N, --threads N`: ��⠭���� ������⢮ ��⮪��, ����� ���� �ᯮ�짮������ �� �६� �����樨. ��� ��⨬��쭮� �ந�����⥫쭮�� ४��������� ��⠭����� �� ���祭�� ࠢ�� �������� 䨧��᪨� 拉� ������, �������� � ��襩 ��⥬� (� �⫨稥 �� �����᪮�� ������⢠ 拉�). �ᯮ�짮����� �ࠢ��쭮�� ������⢠ ��⮪�� ����� ����⥫쭮 ������� �ந�����⥫쭮���.
- `-tb N, --threads-batch N`: ��⠭���� ������⢮ ��⮪��, ����� ���� �ᯮ�짮������ �� �६� ����⭮� � ����⨢��� ��ࠡ�⪨. � �������� ��⥬�� �룮��� �ᯮ�짮���� ����襥 ������⢮ ��⮪�� �� �६� ����⭮� ��ࠡ�⪨, 祬 �� �६� �����樨. �᫨ �� 㪠����, ������⢮ ��⮪��, �ᯮ��㥬�� ��� ����⭮� ��ࠡ�⪨, �㤥� ⠪�� ��, ��� ������⢮ ��⮪��, �ᯮ��㥬�� ��� �����樨.

### Mlock

- `--mlock`: �������� ������ � �����, �।����� �� ���㧪� �� ᮯ��⠢����� � �������. �� ����� ������� �ந�����⥫쭮���, �� ᢮��� �� ��� ������� �२����⢠ ᮯ��⠢����� � �������, ��᪮��� ��� ����᪠ �ॡ���� ����� ����⨢��� ����� � ��⥭樠�쭮 ���������� �६� ����㧪� ������ � ���.

### ��� ᮯ��⠢����� � �������

- `--no-mmap`: �� �⮡ࠦ��� ������ � ������. �� 㬮�砭�� ������ �⮡ࠦ����� � ������, �� �������� ��⥬� ����㦠�� ⮫쪮 ����室��� ��� ������ �� ��� ����室�����. ������, �᫨ ࠧ��� ������ �ॢ�蠥� ��騩 ��ꥬ ����⨢��� ����� ��� �᫨ � ��襩 ��⥬� �������筮 ����㯭�� �����, �ᯮ�짮����� mmap ����� 㢥����� �� �믠����� ��࠭��, �� ����⨢�� ᪠����� �� �ந�����⥫쭮��. �⪫�祭�� mmap �ਢ���� � ���������� ����㧪�, �� ����� 㬥����� ������⢮ ��ᬮ�஢ ��࠭��, �᫨ �� �� �ᯮ���� `--mlock`. ����� ��������, �� �᫨ ࠧ��� ������ �ॢ�蠥� ��騩 ��ꥬ ����⨢��� �����, �⪫�祭�� mmap ����� �।����� ����㧪� ������.

### �����প� NUMA

- `--��।������ numa`: �ਪ९�� ࠢ��� ���� ��⮪�� � �ࠬ �� ������ 㧫� NUMA. �� ��।���� ����㧪� ����� �ᥬ� �ࠬ� ��⥬�, ��������� �� ������ ����� �� ��� ��⥭樠�쭮� ����室����� ��।�� ����� �� �������� ������� �裡 ����� 㧫���.
- `--numa isolate`: �ਢ易�� �� ��⮪� � 㧫� NUMA, �� ���஬ ����᪠���� �ணࠬ��. �� ��࠭�稢��� ������⢮ 拉� � ��ꥬ �����, ����� ����� ���� �ᯮ�짮����, �� ��࠭����, �� ���� ����� � ����� ��⠥��� ������� ��� 㧫� NUMA.
- `--numa numactl`: �ਢ易�� ��⮪� � CPUMAP, ����� ��।����� �ணࠬ��, �����⨢ �� � ������� �⨫��� numactl. �� �������� ������ ०��, ��������騩 �ᯮ�짮���� �ந������ 蠡���� �ᯮ�짮����� 拉�, ���ਬ��, �����, ����� �ᯮ���� �� �� �� ����� 㧫� NUMA � �����筮� ������⢮ 拉� �� ��஬ 㧫� ��� ����饭�� ���㧫���� 設� �����.

 �� 䫠�� ��������� �믮����� ��⨬�����, ����� �������� � �������� ��⥬�� � ��ࠢ������ ����㯮� � �����. � �����饥 �६� �� ����砥� � ᥡ� ���� �� ���㪠������ ���⥣�� � �⪫�祭�� �।���⥫쭮� �롮ન � readahead ��� mmap. ��᫥���� �ਢ���� � ᡮ� ᮯ��⠢������ ��࠭�� �� ��ࢮ� ����㯥, � �� �� �ᥬ �ࠧ�, � � ��⠭�� � �ਢ離�� ��⮪�� � 㧫�� NUMA ����襥 ������⢮ ��࠭�� ����뢠���� �� 㧫� NUMA, ��� ��� �ᯮ�������. ����� ��������, �� �᫨ ������ 㦥 ��室���� � ��⥬��� ��� ��࠭��, ���ਬ��, ��-�� �।��饣� ����᪠ ��� �⮩ ��樨, �� �㤥� ����� ������⥫�� ��䥪�, �᫨ �� ᭠砫� �� 㤠��� ��� ��࠭��. �� ����� ᤥ����, ��१���㧨� ��⥬� ��� � Linux, ����ᠢ '3' � '/proc/sys/vm/drop_caches' �� ����� root.

### ��ꥬ ����� 32

- `--memory-f32`: �ᯮ���� 32-ࠧ�來� ���祭�� � ������饩 ����⮩ ����� 16-ࠧ�來�� ���祭�� � ������饩 ����⮩ ��� ���� �����+���祭��. �� 㤢������ �ॡ������ � ���⥪�⭮� ����� � ࠧ��� ���஢������ 䠩�� �����, ��, ��-��������, �� ����蠥� ����⢮ �����樨 ����ਬ� ��ࠧ��. �� ४���������.

### ������ ���⨨

- `-b N, --batch-size N`: ��⠭���� ࠧ��� ����� ��� ����⨢��� ��ࠡ�⪨ (�� 㬮�砭��: 512). ��� ����让 ࠧ��� ����� �룮��� ���짮��⥫�, � ������ BLAS ��⠭����� � ����祭 �� �६� ᡮન. �᫨ � ��� �� ����祭 BLAS ("BLAS=0"), �� ����� �ᯮ�짮���� ����襥 �᫮, ���ਬ�� 8, �⮡� 㢨���� 室 �믮������ ����� �� ��� ��� �業�� � �������� ������.


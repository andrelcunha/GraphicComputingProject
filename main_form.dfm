object Form1: TForm1
  Left = 278
  Top = 242
  Width = 449
  Height = 424
  Caption = 'Transforma'#231#245'es Geom'#233'tricas'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 200
    Top = 16
    Width = 107
    Height = 13
    Caption = 'Opera'#231#245'es dispon'#237'veis'
  end
  object Label3: TLabel
    Left = 200
    Top = 86
    Width = 90
    Height = 13
    Caption = 'Pilha de opera'#231#245'es'
  end
  object Label4: TLabel
    Left = 74
    Top = 263
    Width = 81
    Height = 13
    Caption = 'Matriz resultante'
  end
  object Label1: TLabel
    Left = 50
    Top = 33
    Width = 6
    Height = 13
    Alignment = taCenter
    Caption = 'X'
  end
  object Label5: TLabel
    Left = 89
    Top = 33
    Width = 6
    Height = 13
    Alignment = taCenter
    Caption = 'Y'
  end
  object Label6: TLabel
    Left = 8
    Top = 16
    Width = 120
    Height = 13
    Alignment = taCenter
    Caption = 'Coordenadas dos pontos'
  end
  object Label7: TLabel
    Left = 128
    Top = 52
    Width = 7
    Height = 13
    Caption = 'A'
  end
  object Label8: TLabel
    Left = 128
    Top = 79
    Width = 6
    Height = 13
    Caption = 'B'
  end
  object Label9: TLabel
    Left = 128
    Top = 107
    Width = 7
    Height = 13
    Caption = 'C'
  end
  object Label10: TLabel
    Left = 128
    Top = 133
    Width = 7
    Height = 13
    Caption = 'D'
  end
  object Label11: TLabel
    Left = 128
    Top = 160
    Width = 6
    Height = 13
    Caption = 'E'
  end
  object Label12: TLabel
    Left = 319
    Top = 16
    Width = 55
    Height = 13
    Caption = 'Par'#226'metros'
  end
  object Label13: TLabel
    Left = 319
    Top = 33
    Width = 6
    Height = 13
    Alignment = taCenter
    Caption = '1'
  end
  object Label14: TLabel
    Left = 354
    Top = 33
    Width = 6
    Height = 13
    Alignment = taCenter
    Caption = '2'
  end
  object save_button: TButton
    Left = 8
    Top = 194
    Width = 75
    Height = 25
    Caption = 'Salvar'
    TabOrder = 0
    OnClick = save_buttonClick
  end
  object clean_button: TButton
    Left = 89
    Top = 194
    Width = 75
    Height = 25
    Caption = 'Limpar'
    TabOrder = 1
  end
  object op_list: TListBox
    Left = 200
    Top = 105
    Width = 90
    Height = 76
    ItemHeight = 13
    TabOrder = 2
  end
  object op_combo: TComboBox
    Left = 200
    Top = 52
    Width = 90
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 3
    OnSelect = op_comboChange
    Items.Strings = (
      'Transla'#231#227'o'
      'Escala'
      'Rota'#231#227'o'
      'Cisalhamento')
  end
  object add_button: TButton
    Left = 215
    Top = 194
    Width = 75
    Height = 25
    Caption = 'Adicionar'
    TabOrder = 4
    OnClick = add_buttonClick
  end
  object result_grid: TStringGrid
    Left = 74
    Top = 282
    Width = 201
    Height = 81
    ColCount = 3
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    TabOrder = 5
  end
  object Edit1_x: TEdit
    Left = 50
    Top = 52
    Width = 33
    Height = 21
    TabOrder = 6
    Text = '0,5'
  end
  object Edit2_y: TEdit
    Left = 89
    Top = 79
    Width = 33
    Height = 21
    TabOrder = 7
    Text = '-0,5'
  end
  object Edit2_x: TEdit
    Left = 50
    Top = 79
    Width = 33
    Height = 21
    TabOrder = 8
    Text = '0,5'
  end
  object Edit3_x: TEdit
    Left = 50
    Top = 106
    Width = 33
    Height = 21
    TabOrder = 9
    Text = '-0,5'
  end
  object Edit5_x: TEdit
    Left = 50
    Top = 160
    Width = 33
    Height = 21
    TabOrder = 10
    Text = '0'
  end
  object Edit4_x: TEdit
    Left = 50
    Top = 133
    Width = 33
    Height = 21
    TabOrder = 11
    Text = '-0,5'
  end
  object Edit4_y: TEdit
    Left = 89
    Top = 133
    Width = 33
    Height = 21
    TabOrder = 12
    Text = '0,4'
  end
  object Edit3_y: TEdit
    Left = 89
    Top = 106
    Width = 33
    Height = 21
    TabOrder = 13
    Text = '-0,5'
  end
  object Edit1_y: TEdit
    Left = 89
    Top = 52
    Width = 33
    Height = 21
    TabOrder = 14
    Text = '0,4'
  end
  object Edit5_y: TEdit
    Left = 89
    Top = 160
    Width = 33
    Height = 21
    TabOrder = 15
    Text = '0,6'
  end
  object rem_button: TButton
    Left = 308
    Top = 194
    Width = 75
    Height = 25
    Caption = 'Remover'
    TabOrder = 16
    OnClick = rem_buttonClick
  end
  object render_button: TButton
    Left = 200
    Top = 369
    Width = 75
    Height = 25
    Caption = 'Renderizar'
    TabOrder = 17
    OnClick = render_buttonClick
  end
  object op_parm1_edit: TEdit
    Left = 319
    Top = 52
    Width = 29
    Height = 21
    TabOrder = 18
  end
  object op_parm2_edit: TEdit
    Left = 354
    Top = 52
    Width = 29
    Height = 21
    TabOrder = 19
  end
  object op_parm1_list: TListBox
    Left = 319
    Top = 105
    Width = 25
    Height = 76
    ItemHeight = 13
    TabOrder = 20
  end
  object op_parm2_list: TListBox
    Left = 358
    Top = 105
    Width = 25
    Height = 76
    ItemHeight = 13
    TabOrder = 21
  end
end

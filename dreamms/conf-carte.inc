config[graphics]:
    title = Graphics Configuration
    option[cga]:   name = $(CGA_NAME);    videohw = cga; VIDEO_CONFIG = 1
    option[tandy]: name = $(TVIDEO_NAME); videohw = cga; VIDEO_CONFIG = 1; machine = tandy
    option[ega]:   name = $(EGA_NAME);    videohw = ega; VIDEO_CONFIG = 2; priority = 1
    option[mono]:  name = Monochrome;     videohw = cga; VIDEO_CONFIG = 0
end

CONFIGFILE = [[[
    // 00 = Monochrome
    // 01 = CGA / Tandy 1000 SX
    // 02 = EGA
    // 03 = Amstrad PC1512
    // 04 = Amstrad PC1640
    `b:$(VIDEO_CONFIG)
    `b:0
]]]

script[init]:
    code = [[[$(CRLF)
        file_save("$$(rootpath)\\CARTE.INF", "$$(CONFIGFILE)");
    ]]]
end
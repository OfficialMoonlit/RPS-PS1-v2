include ../../Makefile.cfg

all:
	mkdir -p cd_root
	$(CC) $(CCFLAGS)-DVMODE_SELECT=VMODE_NTSC rpsps1.c -o rpsps1.elf
	elf2exe rpsps1.elf RPS_NA_N.02
	cp RPS_NA_N.02 cd_root
	bmp2tim start1l.bmp cd_root/start1l.tim 16 -org=320,0
	bmp2tim start1r.bmp cd_root/start1r.tim 16 -org=480,0
	bmp2tim play1l.bmp cd_root/play1l.tim 16 -org=320,0
	bmp2tim play1r.bmp cd_root/play1r.tim 16 -org=480,0
	bmp2tim rock.bmp cd_root/rock.tim 16 -org=640,170
	bmp2tim paper.bmp cd_root/paper.tim 16 -org=708,100
	bmp2tim scissor.bmp cd_root/scissor.tim 16 -org=708,170
	bmp2tim loading.bmp cd_root/loading.tim 16 -org=320,0
	bmp2tim 0.bmp cd_root/0.tim 16 -org=640,0
	bmp2tim 1.bmp cd_root/1.tim 16 -org=656,0
	bmp2tim 2.bmp cd_root/2.tim 16 -org=672,0
	bmp2tim 3.bmp cd_root/3.tim 16 -org=688,0
	bmp2tim 4.bmp cd_root/4.tim 16 -org=704,0
	bmp2tim 5.bmp cd_root/5.tim 16 -org=720,0
	bmp2tim 6.bmp cd_root/6.tim 16 -org=736,0
	bmp2tim 7.bmp cd_root/7.tim 16 -org=752,0
	bmp2tim 8.bmp cd_root/8.tim 16 -org=768,0
	bmp2tim 9.bmp cd_root/9.tim 16 -org=784,0
	bmp2tim a.bmp cd_root/font/a.tim 16 -org=640,16
	bmp2tim b.bmp cd_root/font/b.tim 16 -org=656,16
	bmp2tim c.bmp cd_root/font/c.tim 16 -org=672,16
	bmp2tim d.bmp cd_root/font/d.tim 16 -org=688,16
	bmp2tim e.bmp cd_root/font/e.tim 16 -org=704,16
	bmp2tim f.bmp cd_root/font/f.tim 16 -org=720,16
	bmp2tim g.bmp cd_root/font/g.tim 16 -org=736,16
	bmp2tim h.bmp cd_root/font/h.tim 16 -org=752,16
	bmp2tim i.bmp cd_root/font/i.tim 16 -org=768,16
	bmp2tim j.bmp cd_root/font/j.tim 16 -org=784,16
	bmp2tim k.bmp cd_root/font/k.tim 16 -org=640,32
	bmp2tim l.bmp cd_root/font/l.tim 16 -org=656,32
	bmp2tim m.bmp cd_root/font/m.tim 16 -org=672,32
	bmp2tim n.bmp cd_root/font/n.tim 16 -org=688,32
	bmp2tim o.bmp cd_root/font/o.tim 16 -org=704,32
	bmp2tim p.bmp cd_root/font/p.tim 16 -org=720,32
	bmp2tim q.bmp cd_root/font/q.tim 16 -org=736,32
	bmp2tim r.bmp cd_root/font/r.tim 16 -org=752,32
	bmp2tim s.bmp cd_root/font/s.tim 16 -org=768,32
	bmp2tim t.bmp cd_root/font/t.tim 16 -org=784,32
	bmp2tim u.bmp cd_root/font/u.tim 16 -org=640,48
	bmp2tim v.bmp cd_root/font/v.tim 16 -org=656,48
	bmp2tim w.bmp cd_root/font/w.tim 16 -org=672,48
	bmp2tim x.bmp cd_root/font/x.tim 16 -org=688,48
	bmp2tim y.bmp cd_root/font/y.tim 16 -org=704,48
	bmp2tim z.bmp cd_root/font/z.tim 16 -org=720,48
	bmp2tim winled.bmp cd_root/winled.tim 16 -org=736,48
	bmp2tim lit50.bmp cd_root/lit50.tim 16 -org=640,64
	bmp2tim litstart.bmp cd_root/litstart.tim 16 -org=640,100
	systemcnf RPS_NA_N.02 > cd_root/system.cnf
	mkisofs.exe -o rpsps1.hsf -V RPS2 -sysid PLAYSTATION cd_root
	mkpsxiso rpsps1.hsf RPS2-NTSC.bin $(CDLIC_FILE)

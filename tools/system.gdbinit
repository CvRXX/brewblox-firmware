define add-symbol-file-auto
  # Parse .text address to temp file
  shell echo set \$text_address=(readelf -WS $arg0 | grep .text | awk '{ print "0x"$5 }') >/tmp/temp_gdb_text_address.txt

  # Source .text address
  source /tmp/temp_gdb_text_address.txt

  #  Clean tempfile
  shell rm -f /tmp/temp_gdb_text_address.txt

  # Load symbol table
  add-symbol-file $arg0 $text_address
end

add-symbol-file-auto external_libs/device-os/build/target/system-part1/platform-8-m/system-part1.elf
add-symbol-file-auto external_libs/device-os/build/target/system-part2/platform-8-m/system-part2.elf

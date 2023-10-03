
																				        }


									        check_elf(header->e_ident);

										        printf("ELF Header:\n");

											        print_magic(header->e_ident);

												        print_class(header->e_ident);

													        print_data(header->e_ident);

														        print_version(header->e_ident);

															        print_osabi(header->e_ident);

																        print_abi(header->e_ident);

																	        print_type(header->e_type, header->e_ident);

																		        print_entry(header->e_entry, header->e_ident);


																			        free(header);

																				        close_elf(o);

																					        return (0);

}

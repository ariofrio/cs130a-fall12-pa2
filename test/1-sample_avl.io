> ./avl
> verbose
> insert 20
< Element inserted
> insert 10
< Element inserted
> insert 2
< Element inserted
> access 2
< Element accessed
> print
< 10 2 20
< 2 10 20
< 10:1(2:0,20:0)
> insert 15
< Element inserted
> insert 18
< Element inserted
> insert 12
< Element inserted
> access 15
< Element accessed
> print
< 15 10 2 12 18 20
< 2 10 12 15 18 20
< 15:2(10:1(2:0,12:0),18:1(,20:0))
> delete 10
< Element deleted
> print
< 15 12 2 18 20
< 2 12 15 18 20
< 15:2(12:1(2:0,),18:1(,20:0))
> delete 18
< Element deleted
> print
< 15 12 2 20
< 2 12 15 20
< 15:2(12:1(2:0,),20:0)
> delete 20
< Element deleted
> print
< 12 2 15
< 2 12 15
< 12:1(2:0,15:0)
> insert 7
< Element inserted
> print
< 12 2 7 15
< 2 7 12 15
< 12:2(2:1(,7:0),15:0)

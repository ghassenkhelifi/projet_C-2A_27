const dc=document.querySelector('#sidebar');
let showorhide = function(){
dc.style.display='block';
}
const d=document.querySelector('#sidebar');
let showorhiden = function(){
d.style.display='none';
}
const toggle=document.getElementById('toggleDark');
const body=document.querySelector('body');
const div=document.querySelector('mud');
toggle.addEventListener('click',function(){
    this.classList.toggle('bi-moon');
    if(this.classList.toggle('bi-brightness-high-fill')){
        body.style.background='white';
        body.style.color= 'black'
        body.style.transition ='2s';
        div.style.background='white';
        div.style.color= 'black'
        div.style.transition ='2s';
    }else{
        body.style.background='black';
        body.style.color= 'white'
        body.style.transition ='2s';
        div.style.background='white';
        div.style.color= 'black'
        div.style.transition ='2s';
    }
})